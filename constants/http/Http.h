#ifndef HTTP_H
#define HTTP_H

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
}

#endif
