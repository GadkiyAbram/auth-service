#include "Router.h"
#include <boost/asio/write.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include "bcrypt/BCrypt.hpp"
#include "../../services/user/UserDTO.h"
#include "../../services/user/UserRepository.h"
#include "../../constants/http/methods/Methods.h"
#include "../../constants/http/Http.h"
#include "../../constants/routes/Routes.h"
#include "../../constants/entities/Entities.h"
#include "../../constants/auth/Auth.h"
#include "../../constants/env/Env.h"
#include "../../database/DBConnection.h"
#include "../../models/Auth/jwt/JWTAuth.h"

using json = nlohmann::json;
using namespace std;

namespace HttpMethods = Methods;
namespace UserKeys = User;

Router::Router() {
    get_routes_[Routes::DEFAULT] = [](const string &body) -> json {
        return {
            {"status", HttpCodeMessages::OK},
            {"data", {{"message", HttpDummy::MESSAGE_WELCOME}}}
        };
    };

    get_routes_[Routes::ABOUT] = [](const string &body) -> json {
        string response = HttpDummy::MESSAGE_ABOUT;

        return {
            {"status", HttpCodeMessages::OK},
            {"data", {{"message", HttpDummy::MESSAGE_ABOUT}}}
        };
    };

    post_routes_[Routes::LOGIN] = [](const string &body) -> json {
        try {
            json json_data = json::parse(body);
            string username = json_data[UserKeys::USERNAME];
            string password = json_data[UserKeys::PASSWORD];
            std::string old_token =
                    json_data.contains(UserKeys::TOKEN) ? json_data[UserKeys::TOKEN].get<std::string>() : "";

            const DBConnection &dbConnection = DBConnection::getInstance();
            UserRepository userRepository(dbConnection);

            UserDTO user = userRepository.getUser(username);

            if (BCrypt::validatePassword(password, user.getPassword())) {
                if (user.getAuthType() == AuthType::JWT) {
                    std::string jwtSecret = std::getenv(EnvKeys::JWT_SECRET.c_str());

                    JWTAuth jwtAuth(jwtSecret);
                    std::string newToken = jwtAuth.authenticate(old_token, username);

                    return {
                        {"status", HttpCodeMessages::OK},
                        {"data", {{"token", newToken}}}
                    };
                }
            } else {
                return {
                    {"status", HttpCodeMessages::NOT_AUTHORIZED},
                    {"data", {{"message", HttpCommon::INVALID_CREDENTIALS}}}
                };
            }
        } catch (json::parse_error &e) {
            std::cout << HttpCodeMessages::BAD_REQUEST << std::endl;
            std::cout << e.what() << std::endl;

            return {
                {"status", HttpCodeMessages::BAD_REQUEST},
                {"data", {{"message", HttpCommon::INVALID_JSON}}}
            };
        }

        return {
            {"status", HttpCodeMessages::BAD_REQUEST},
            {"data", {{"message", HttpCommon::INVALID_JSON}}}
        };
    };

    post_routes_[Routes::CREATE_USER] = [](const string &body) -> json {
        json json_data = json::parse(body);
        string username = json_data[UserKeys::USERNAME];
        string password = json_data[UserKeys::PASSWORD];

        const DBConnection &dbConnection = DBConnection::getInstance();

        UserRepository userRepository(dbConnection);

        try {
            std::string response = userRepository.createUser(username, password) ? "true" : "false";

            std::cout << response << std::endl;

            return {
                {"status", HttpCodeMessages::OK},
                {"data", {{"created", response}}}
            };
        } catch (json::parse_error &e) {
            std::cout << HttpCodeMessages::BAD_REQUEST << std::endl;
        }

        return {
            {"status", HttpCodeMessages::BAD_REQUEST},
            {"data", {"message", HttpCommon::INVALID_JSON}}
        };
    };
}

json Router::route(
        const string &method,
        const string &path,
        const string &body
) {
    if (method == Methods::GET && get_routes_.count(path)) {
        return get_routes_[path](body);
    } else if (method == Methods::POST && post_routes_.count(path)) {
        return post_routes_[path](body);
    } else {
        return {
            {"status", HttpCodeMessages::NOT_FOUND},
            {"data", {{"message", HttpCommon::ROUTE_NOT_FOUND}}}
        };
    }
}
