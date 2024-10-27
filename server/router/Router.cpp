#include "Router.h"
#include <boost/asio/write.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include "../../constants/http/methods/Methods.h"
#include "../../constants/http/Http.h"
#include "../../constants/routes/Routes.h"

using json = nlohmann::json;

Router::Router() {
    get_routes_[Routes::DEFAULT] = [](const string& body) -> std::pair<std::string, std::string> {
        string response = "Welcome to the Home Page!!!";

        return std::make_pair(HttpCodeMessages::OK, response);
    };

    get_routes_[Routes::ABOUT] = [](const string& body) -> std::pair<std::string, std::string> {
        string response = "This is a very Cool Gyrodata Application in being developed!!!";

        return std::make_pair(HttpCodeMessages::OK, response);
    };

    post_routes_[Routes::LOGIN] = [](const string& body) -> std::pair<std::string, std::string> {
        try {
            json json_data = json::parse(body);
            string username = json_data["username"];

            string response = "Received username: " + username;

            return std::make_pair(HttpCodeMessages::OK, string (response));
        } catch (json::parse_error& e) {
            std::cout << "400 Bad Request" << std::endl;
        }

        return std::make_pair(HttpCodeMessages::BAD_REQUEST, HttpCommon::INVALID_JSON);
    };
}

std::pair<string, string> Router::route(
        const string& method,
        const string& path,
        const string& body
        ) {
    if (method == Methods::GET && get_routes_.count(path)) {
        return get_routes_[path](body);
    } else if (method == Methods::POST && post_routes_.count(path)) {
        return post_routes_[path](body);
    } else {
        return std::make_pair(HttpCodeMessages::NOT_FOUND, HttpCommon::ROUTE_NOT_FOUND);
    }
}
