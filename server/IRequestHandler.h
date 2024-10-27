#ifndef IREQUESTHANDLER_H
#define IREQUESTHANDLER_H

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class IRequestHandler {
public:
    virtual void handle_request(tcp::socket& socket) = 0;

    virtual ~IRequestHandler() = default;
};

#endif
