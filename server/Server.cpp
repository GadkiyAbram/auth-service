//
// Created by aleksandr on 23.06.24.
//

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
#include "../constants/http/Methods.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <boost/asio.hpp>

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
        // Accept a new connection
        tcp::socket socket(io_context_);
        acceptor_.accept(socket);

        // Handle the client in a separate function
        handle_request(std::move(socket));
    }
}

void Server::handle_request(tcp::socket socket) {
    try {
        // Read the request headers
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\r\n\r\n");  // Read until end of headers

        std::istream is(&buffer);
        std::string request_line;
        std::getline(is, request_line);

        std::cout << "Raw request line: " << request_line << std::endl;

        // Extract the request line, headers, and body
        std::string method;
        std::string path;
        std::string version;

        std::istringstream request_stream(request_line);
        request_stream >> method >> path >> version;

        // Read remaining headers
        std::string header;
        while (std::getline(is, header) && header != "\r") {
            std::cout << "Header: " << header << std::endl;
        }

        // Read the rest of the data (assuming content-length is known or until EOF)
        std::string body;
        std::ostringstream body_stream;
        body_stream << is.rdbuf();
        body = body_stream.str();

        std::cout << "Received data: " << body << std::endl;

        if (method == Methods::POST) {
            try {
                // Parse JSON
                json json_data = json::parse(body);
                std::string username = json_data["username"];
                std::cout << "Parsed username: " << username << std::endl;

                // Respond to client
                std::string response = "Received username: " + username;
                std::string http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: " + std::to_string(response.size()) + "\r\n\r\n" + response;

                boost::asio::write(socket, boost::asio::buffer(http_response));
            } catch (json::parse_error& e) {
                std::cerr << "JSON parse error: " << e.what() << std::endl;
                std::string response = "Invalid JSON";
                std::string http_response = "HTTP/1.1 400 Bad Request\r\nContent-Type: text/plain\r\nContent-Length: " + std::to_string(response.size()) + "\r\n\r\n" + response;

                boost::asio::write(socket, boost::asio::buffer(http_response));
            }
        } else {
            std::string response = "Method not supported";
            std::string http_response = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\nContent-Length: " + std::to_string(response.size()) + "\r\n\r\n" + response;

            boost::asio::write(socket, boost::asio::buffer(http_response));
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

//void Server::handle_request(int client_socket) {
//    const int buffer_size = 1024;
//
//    char buffer[buffer_size];
//    memset(buffer, 0, buffer_size);
//    read(client_socket, buffer, buffer_size);
//
//    string request(buffer);
//
//    string path = parse_request(request);
//
//    cout << "\nPATH:" << path << "\n";
//
//    if (path == "/") {
//        const char* responseText = "Welcome to C++ application!";
//
//        send_response(
//            client_socket,
//            HttpConstants::RESPONSE_OK,
//            HttpConstants::TEXT_PLAIN,
//            responseText
//        );
//    } else if (path == "/login") {
//        handle_login(client_socket);
//    } else {
//        const char* responseText = "Nothing found here";
//
//        send_response(
//            client_socket,
//            HttpConstants::RESPONSE_NOT_FOUND,
//            HttpConstants::TEXT_PLAIN,
//            responseText
//        );
//    }
//}

void Server::send_response(
    int client_socket, 
    const string& status, 
    const string& content_type, 
    const string& body
    ) {
    ostringstream response;
    response << "HTTP/1.1 " << status << "\r\n"
             << "Content-Type: " << content_type << "\r\n"
             << "Content-Length: " << body.size() << "\r\n"
             << "\r\n"
             << body;

    string response_str = response.str();
    send(client_socket, response_str.c_str(), response_str.size(), 0);
}

void Server::handle_login(int client_socket) {
    const DBConnection& dbConnection = DBConnection::getInstance();
    PGconn* conn = dbConnection.connection;

    int flags = fcntl(client_socket, F_GETFL, 0);
    if (flags == -1) {
        std::cerr << "Error getting socket flags: " << strerror(errno) << std::endl;

        return;
    }

    // Clear non-blocking flag
    if (fcntl(client_socket, F_SETFL, flags & ~O_NONBLOCK) == -1) {
        std::cerr << "Error setting socket to blocking mode: " << strerror(errno) << std::endl;

        return;
    }

    string request = read_from_socket(client_socket);

    cout << "\nRequest" << request << endl;

    const string username = "gadkiyabram";

    string query = "SELECT * FROM users WHERE username = '" + string(username) + "'";

    PGresult* res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);

        if (nRows > 0) {
            const char* responseText = "Login successfull!";

            send_response(
                client_socket,
                HttpConstants::RESPONSE_OK,
                HttpConstants::TEXT_PLAIN, responseText
            );
        } else {
            const char* responseText = "User not found!";

            send_response(
                client_socket,
                HttpConstants::RESPONSE_NOT_AUTHORIZED,
                HttpConstants::TEXT_PLAIN, responseText
            );
        }

        PQclear(res);
    }
}

string Server::read_from_socket(int client_socket) {
    const size_t buffer_size = 4096;
    char buffer[buffer_size];
    std::string data;
    ssize_t bytes_read;

    bool timeout_occurred = false;

    while (true) {
        bytes_read = read(client_socket, buffer, buffer_size - 1);

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';  // Null-terminate the buffer
            data.append(buffer);

            // Check for end of headers or request completion
            if (data.find("\r\n\r\n") != std::string::npos) {
                break;
            }
        } else if (bytes_read == 0) {
            // Client closed the connection
            std::cerr << "Client disconnected" << std::endl;
            break;
        } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
            // Handle timeout
            timeout_occurred = true;
            std::cerr << "Socket read timed out" << std::endl;
            break;
        } else {
            // Other errors
            std::cerr << "Error reading from socket: " << strerror(errno) << std::endl;
            break;
        }
    }

    if (timeout_occurred && data.empty()) {
        // If timeout occurred and no data was received, you might want to handle it differently
        std::cerr << "No data received before timeout" << std::endl;
    }


    std::cerr << "Data received: " << data << std::endl;
    return data;
}
