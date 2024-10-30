#include "UserRepository.h"
#include "../../constants/http//Http.h"
#include <iostream>

UserRepository::UserRepository(const DBConnection& dbConnection) : dbConnection(dbConnection) {}

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
    std::string query = "SELECT username, password FROM users WHERE username = '" + username + "';";
    PGresult* result = dbConnection.query(query);
    if(PQntuples(result) > 0) {
        std::string password = PQgetvalue(result,0, 1);
        PQclear(result);

        return UserDTO(username, password);
    }

    PQclear(result);

    throw std::runtime_error(HttpCommon::USER_NOT_FOUND);
}