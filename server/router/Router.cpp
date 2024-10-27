#include "Router.h"
#include <boost/asio/write.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include "../../constants/http/methods/Methods.h"
#include "../../constants/http/Http.h"

using json = nlohmann::json;

Router::Router() {
    get_routes_["/"] = [](const string& body) {
        string response = "Welcome to the Home Page!";

        string code_message = std::to_string(HttpCodes::OK) + HttpMessages::OK;
        std::cout << code_message << std::endl;

        return std::make_pair("200 OK", response);
    };

    get_routes_["/about"] = [](const string& body) {
        string response = "This is a very Cool Gyrodata Application in being developed!";

        return std::make_pair("200 OK", response);
    };

    post_routes_["/login"] = [](const string& body) {
        try {
            json json_data = json::parse(body);
            string username = json_data["username"];

            string response = "Received username: " + username;

            return std::make_pair("200 OK", response);
        } catch (json::parse_error& e) {
            std::cout << "400 Bad Request" << std::endl;
        }

        return std::make_pair("400 Bad Request", string("Invalid JSON"));
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
        return std::make_pair("404 Not Found", "Route not found");
    }
}
