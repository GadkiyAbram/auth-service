#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include "IRequestHandler.h"

using namespace std;
using boost::asio::ip::tcp;

class Server : public IRequestHandler {
public:
    Server(boost::asio::io_context& io_context, int port);
    int port;
    void launch();

    void handle_request(tcp::socket& socket) override;

private:
    int server_socket;

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};

#endif
