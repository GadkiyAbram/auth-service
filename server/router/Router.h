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

class Router {
public:
    using Handler = std::function<void(tcp::socket&, const std::string&)>;

    Router();

    json route(
            const std::string& method,
            const std::string& path,
            const std::string& body
            );
private:
    std::map<std::string, std::function<json(const std::string&)>> get_routes_;
    std::map<std::string, std::function<json(const std::string&)>> post_routes_;

    json formatResponse(
        const std::string& status,
        const json& result
        );
};

#endif
