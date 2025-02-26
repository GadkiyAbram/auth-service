#include "Server.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <sstream>
#include <string>
#include "../database/DBConnection.h"
#include <postgresql/libpq-fe.h>
#include "../constants/http/HttpConstants.hpp"
#include "../constants/http/Http.h"
#include "../constants/http/methods/Methods.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <boost/asio.hpp>
#include "./router/Router.h"

using namespace std;
using boost::asio::ip::tcp;
using json = nlohmann::json;

Server::Server(
        boost::asio::io_context& io_context,
        int port
        )
        : io_context_(io_context), acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    std::cout << "Server is carefully listening on port " << port << std::endl;
}

void Server::launch() {
    while (true) {
        tcp::socket socket(io_context_);
        acceptor_.accept(socket);

        handle_request(socket);
    }
}

void Server::handle_request(tcp::socket& socket) {
    try {
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\r\n\r\n");

        istream is(&buffer);
        string request_line;
        getline(is, request_line);

        string method;
        string path;
        string version;

        istringstream request_stream(request_line);
        request_stream >> method >> path >> version;

        // Read remaining headers
        string header;
        while (std::getline(is, header) && header != "\r") {
            std::cout << "Header: " << header << std::endl;
        }

        // Read the rest of the data (assuming content-length is known or until EOF)
        string body;
        ostringstream body_stream;
        body_stream << is.rdbuf();
        body = body_stream.str();

        Router router;

        std::pair<string, string> response = router.route(method, path, body);

        json jsonResponse;

        jsonResponse["status"] = response.first == HttpCodeMessages::OK ? "success" : "error" ;
        jsonResponse["data"] = response.second;

        string json_str = jsonResponse.dump();

        string http_response = "HTTP/1.1 " + response.first +
                "\r\nContent-Type: application/json\r\nContent-Length: " +
                std::to_string(json_str.size()) +
                "\r\n\r\n" +
                json_str;

        boost::asio::write(socket, boost::asio::buffer(http_response));
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
