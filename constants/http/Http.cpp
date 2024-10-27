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
    const string BAD_REQUEST = "BAD_REQUEST";
    const string NOT_AUTHORIZED = "NOT_AUTHORIZED";
    const string NOT_FOUND = "NOT_FOUND";
    const string METHOD_NOT_ALLOWED = "METHOD_NOT_ALLOWED";
    const string SERVER_ERROR = "SERVER_ERROR";
}

namespace HttpCommon {
    const string INVALID_JSON = "Invalid JSON";
}