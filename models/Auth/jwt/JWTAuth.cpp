#include "JWTAuth.h"
#include <jwt-cpp/jwt.h>
#include <chrono>
#include <iostream>
#include "../../../constants/entities/Entities.h"

namespace UserKeys = User;

JWTAuth::JWTAuth(const std::string &secretKey) : secretKey(secretKey) {}

std::string JWTAuth::authenticate(const std::string &token, const std::string &username) const {
    if (token.empty()) {
        return this->generateToken(username);
    }

    try {
        auto decodedToken = jwt::decode(token);

        // @todo verifier and verifier.verify(decodedToken) looks unnecessary here
        auto verifier = jwt::verify()
                .allow_algorithm(jwt::algorithm::hs256{secretKey})
                .with_issuer("auth0");

        verifier.verify(decodedToken);

        return isTokenExpired(decodedToken) ?
               this->generateToken(username) :
               token;
    } catch (const std::exception&e) {
        std::cerr << "Token validation error: " << e.what() << std::endl;

        return this->generateToken(username);
    }
}

bool JWTAuth::isTokenExpired(const jwt::decoded_jwt<jwt::traits::kazuho_picojson>& decodedToken) const {
    auto expiring = decodedToken.get_expires_at();
    auto now = std::chrono::system_clock::now();

    return now > expiring;
}

std::string JWTAuth::generateToken(const std::string &username) const {
    auto token = jwt::create()
            .set_issuer("auth0")
            .set_payload_claim(UserKeys::USERNAME, jwt::claim(username))
            .set_expires_at(std::chrono::system_clock::now() + std::chrono::hours(1))
            .sign(jwt::algorithm::hs256{secretKey});

    return token;
}

bool JWTAuth::verify(const std::string &token) const {
    try {
        auto decodedToken = jwt::decode(token);

        auto verifier = jwt::verify()
                .allow_algorithm(jwt::algorithm::hs256{secretKey})
                .with_issuer("auth0");

        verifier.verify(decodedToken);

        return true;
    } catch (const std::exception&e) {
        return false;
    }

    return false;
}