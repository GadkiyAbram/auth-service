#include "server/Server.h"
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;
using namespace std;
using namespace std::string_literals;

int main() {
    try {
        boost::asio::io_context io_context;
        const int port = 8080;

        // Create and run the server
        Server server(io_context, port);
        server.launch();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
