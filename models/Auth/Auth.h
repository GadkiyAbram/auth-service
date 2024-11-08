#ifndef AUTH_H
#define AUTH_H

#include <string>

using namespace std;

class Auth {
public:
    virtual std::string authenticate(const std::string& token, const std::string &username) const = 0;

    virtual ~Auth() = default;
};

#endif
