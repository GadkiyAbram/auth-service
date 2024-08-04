//
// Created by aleksandr on 23.06.24.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <string>
#include "../database/DBConnection.h"
#include <postgresql/libpq-fe.h>
#include "../constants/http/HttpConstants.hpp"

using namespace std;

Server::Server(int port) : port(port) {
    std::cout << "Initializing server with port: " << port << std::endl;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        cerr << "Error creating socket\n";

        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        cerr << "Binding failed\n";

        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        cerr << "Listening failed\n";

        close(server_socket);
        exit(EXIT_FAILURE);
    }

    cout << "Server initialized on port " << this->port << "...\n";
}

void Server::launch() {
    while (true) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

        if (client_socket < 0) {
            cout << "Error accepting connection\n";
        }

        handle_request(client_socket);

        close(client_socket);
    }
}

void Server::handle_request(int client_socket) {
    const int buffer_size = 1024;
    char buffer[buffer_size];
    memset(buffer, 0, buffer_size);
    read(client_socket, buffer, buffer_size);

    string request(buffer);
    string path = parse_request(request);

    cout << "\nPATH:" << path << "\n";

    if (path == "/") {
        const char* responseText = "Welcome to C++ application!";
        
        send_response(
            client_socket, 
            HttpConstants::RESPONSE_OK, 
            HttpConstants::TEXT_PLAIN, 
            responseText
        );
    } else if (path == "/login") {
        handle_login(client_socket);
    } else {
        const char* responseText = "Nothing found here";

        send_response(
            client_socket, 
            HttpConstants::RESPONSE_NOT_FOUND, 
            HttpConstants::TEXT_PLAIN, 
            responseText
        );
    }
}

string Server::parse_request(const string& request) {
    istringstream request_stream(request);
    string method;
    string path;

    request_stream >> method >> path;

    return path;
}

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

    const char* username = "gadkiyabram";
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
