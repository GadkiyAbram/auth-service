#ifndef HTTP_CONSTANTS_HPP
#define HTTP_CONSTANTS_HPP

#include <string>

using namespace std;

namespace HttpConstants
{
    const string TEXT_PLAIN = "text/plain";

    string RESPONSE_OK = "200";
    string RESPONSE_NOT_FOUND = "404";
    string RESPONSE_NOT_AUTHORIZED = "403";
    string RESPONSE_SERVER_ERROR = "500";
}

#endif
