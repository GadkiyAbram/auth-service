#include "server/Server.h"
#include <boost/asio/ip/tcp.hpp>
#include <dotenv.h>

using boost::asio::ip::tcp;
using namespace std;
using namespace std::string_literals;

int main() {
    try {
        dotenv::init();

        boost::asio::io_context io_context;
        const int port = 8080;

        Server server(io_context, port);
        server.launch();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
