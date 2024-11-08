#include "UserRepository.h"
#include "../../constants/http//Http.h"
#include "../../constants/auth/Auth.h"
#include <iostream>
#include "bcrypt/BCrypt.hpp"
#include <random>
#include <sstream>

UserRepository::UserRepository(const DBConnection& dbConnection) : dbConnection(dbConnection) {}

bool UserRepository::createUser(
        const std::string &username,
        const std::string &password
        ) {
    if (this->userExists(username)) {
        throw std::runtime_error(HttpCommon::USER_ALREADY_EXISTS);
    }

    std::string hashedPassword = !password.empty() ?
            hashPassword(password) :
            hashPassword(generatePassword(10));

    std::string query = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + hashedPassword + "');";

    try {
        if (!dbConnection.insert(query)) {
            throw std::runtime_error("Failed to create user in the database.");
        }

        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error in createUser: " << e.what() << std::endl;

        throw;
    }
}

bool UserRepository::userExists(const std::string &username) const {
    std::string query = "SELECT COUNT(*) FROM users WHERE username = '" + username + "';";

    PGresult* result = dbConnection.query(query);
    if (PQntuples(result) > 0) {
        int count = std::stoi(PQgetvalue(result, 0, 0));
        PQclear(result);

        return count > 0;
    }

    PQclear(result);

    return false;
}

UserDTO UserRepository::getUser(const std::string &username) const {
    std::string query = "SELECT username, password, authType FROM users WHERE username = '" + username + "';";
    PGresult* result = dbConnection.query(query);
    if (PQntuples(result) > 0) {
        std::string password = PQgetvalue(result,0, 1);

        int authType = AuthType::JWT;

        try {
            authType = std::stoi(PQgetvalue(result,0, 2));
        } catch (const std::invalid_argument& e) {
            std::cerr << HttpCommon::INVALID_AUTHTYPE_VALUE << PQgetvalue(result, 0, 2) << std::endl;
        }

        PQclear(result);

        return UserDTO(username, password, authType);
    }

    PQclear(result);

    throw std::runtime_error(HttpCommon::USER_NOT_FOUND);
}

string UserRepository::generatePassword(int length) {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::ostringstream password;

    for (int i = 0; i < length; ++i) {
        password << chars[dist(rng)];
    }

    return password.str();
}

string UserRepository::hashPassword(const std::string& password) {
    return BCrypt::generateHash(password);
}