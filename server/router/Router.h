#ifndef ROUTER_H
#define ROUTER_H

#include <boost/asio.hpp>
#include <unordered_map>
#include <functional>
#include <memory>
#include <map>
#include <string>

using boost::asio::ip::tcp;
using namespace std;

class Router {
public:
    using Handler = std::function<void(tcp::socket&, const string&)>;

    Router();

    std::pair<string, string> route(
            const string& method,
            const string& path,
            const string& body
            );
private:
    std::map<string, std::function<std::pair<string, string>(const string&)>> get_routes_;
    std::map<string, std::function<std::pair<string, string>(const string&)>> post_routes_;
};

#endif
