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
#include "../constants/common/Common.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <boost/asio.hpp>
#include "./router/Router.h"
#include "../constants/auth/Auth.h"

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
        json response = router.route(method, path, body);

        std::string http_response = this->format_response(response);

        boost::asio::write(socket, boost::asio::buffer(http_response));
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

std::string Server::format_response(json &response) {
    std::string http_response = "";

    http_response
        .append("HTTP/1.1 ")
        .append(response[Common::STATUS]);

    if (response[Common::DATA].contains(AuthResponseKeys::TOKEN)) {
        std::string token = response[Common::DATA][AuthResponseKeys::TOKEN];
        http_response
            .append("\r\nSet-Cookie: token=")
            .append("Bearer ")
            .append(token)
            .append("; HttpOnly; Secure; SameSite=Strict");

        response[Common::DATA][AuthResponseKeys::TOKEN] = true;
    }

    std::string json_str = response[Common::DATA].dump();

    http_response
        .append("\r\nContent-Type: application/json\r\nContent-Length: ")
        .append(std::to_string(json_str.size()))
        .append("\r\n\r\n")
        .append(json_str);

    return http_response;
}
