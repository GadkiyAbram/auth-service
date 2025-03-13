#ifndef ROUTER_H
#define ROUTER_H

#include <boost/asio.hpp>
#include <unordered_map>
#include <functional>
#include <memory>
#include <map>
#include <string>
#include <nlohmann/json.hpp>

using boost::asio::ip::tcp;
using json = nlohmann::json;
using namespace std;

class Router {
public:
    using Handler = std::function<void(tcp::socket&, const string&)>;

    Router();

    json route(
            const string& method,
            const string& path,
            const string& body
            );
private:
    std::map<string, std::function<json(const string&)>> get_routes_;
    std::map<string, std::function<json(const string&)>> post_routes_;
};

#endif
