#ifndef JWTAUTH_H
#define JWTAUTH_H

#include <string>
#include "../Auth.h"
#include <jwt-cpp/jwt.h>

using namespace std;

class JWTAuth : public Auth {
public:
    JWTAuth(const std::string& secretKey);

    std::string authenticate(const std::string& token, const std::string &username) const override;

private:
    std::string secretKey;

    bool isTokenExpired(const jwt::decoded_jwt<jwt::traits::kazuho_picojson> &decodedToken) const;
    std::string generateToken(const std::string &username) const;
    bool verify(const std::string &token) const;
};

#endif
