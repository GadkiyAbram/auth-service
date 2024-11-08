#ifndef HTTP_CONSTANTS_H
#define HTTP_CONSTANTS_H

#include <string>

using namespace std;

namespace HttpCodes {
    extern const int OK;
    extern const int BAD_REQUEST;
    extern const int NOT_AUTHORIZED;
    extern const int NOT_FOUND;
    extern const int METHOD_NOT_ALLOWED;
    extern const int SERVER_ERROR;
}

namespace HttpMessages {
    extern const string OK;
    extern const string BAD_REQUEST;
    extern const string NOT_AUTHORIZED;
    extern const string NOT_FOUND;
    extern const string METHOD_NOT_ALLOWED;
    extern const string SERVER_ERROR;
}

namespace HttpCodeMessages {
    extern const string OK;
    extern const string BAD_REQUEST;
    extern const string NOT_AUTHORIZED;
    extern const string NOT_FOUND;
    extern const string METHOD_NOT_ALLOWED;
    extern const string SERVER_ERROR;
}

namespace HttpCommon {
    extern const string INVALID_JSON;
    extern const string ROUTE_NOT_FOUND;
    extern const string USER_NOT_FOUND;
    extern const string INVALID_AUTHTYPE_VALUE;
    extern const string INVALID_CREDENTIALS;
    extern const string INVALID_USERNAME_OR_PASSWORD;
    extern const string USER_ALREADY_EXISTS;
}

namespace HttpDummy {
    extern const string MESSAGE_WELCOME;
    extern const string MESSAGE_ABOUT;
}

#endif
