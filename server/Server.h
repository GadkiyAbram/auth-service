//
// Created by aleksandr on 23.06.24.
//

#ifndef SERVER_H
#define SERVER_H

#include <iostream>

using namespace std;

class Server {
public:
    Server(int port);
    int port;
    void launch();

private:
    int server_socket;
    void handle_request(int client_socket);
    string parse_request(const string& request);
    void send_response(
        int client_socket, 
        const std::string& status, 
        const std::string& content_type, 
        const std::string& body
        );
    void handle_login(int client_socket);
};

#endif
