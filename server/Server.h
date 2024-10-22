//
// Created by aleksandr on 23.06.24.
//

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <boost/asio.hpp>
#include <map>

using namespace std;
using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context& io_context, int port);
    int port;
    void launch();

private:
    int server_socket;
//    void handle_request(int client_socket);
    void send_response(
        int client_socket, 
        const std::string& status, 
        const std::string& content_type, 
        const std::string& body
        );
    void handle_login(int client_socket);
    string read_from_socket(int client_socket);

    void handle_request(tcp::socket socket);

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};

#endif
