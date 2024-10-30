#include "Http.h"

namespace HttpCodes {
    const int OK = 200;
    const int BAD_REQUEST = 400;
    const int NOT_AUTHORIZED = 403;
    const int NOT_FOUND = 404;
    const int METHOD_NOT_ALLOWED = 405;
    const int SERVER_ERROR = 500;
}

namespace HttpMessages {
    const string OK = "OK";
    const string BAD_REQUEST = "Bad Request";
    const string NOT_AUTHORIZED = "Not Authorized";
    const string NOT_FOUND = "Not Found";
    const string METHOD_NOT_ALLOWED = "Method Not Allowed";
    const string SERVER_ERROR = "Server Error";
}

namespace HttpCodeMessages {
    const string OK = "200 OK";
    const string BAD_REQUEST = "400 Bad Request";
    const string NOT_AUTHORIZED = "403 Not Authorized";
    const string NOT_FOUND = "404 Not Found";
    const string METHOD_NOT_ALLOWED = "405 Method Not Allowed";
    const string SERVER_ERROR = "500 Server Error";
}

namespace HttpCommon {
    const string INVALID_JSON = "Invalid JSON";
    const string ROUTE_NOT_FOUND = "Route not found";
    const string USER_NOT_FOUND = "User not found";
}

namespace HttpDummy {
    extern const string MESSAGE_WELCOME = "Welcome to the Home Page!!!";
    extern const string MESSAGE_ABOUT = "This is a very Cool Gyrodata Application in being developed!!!";
}