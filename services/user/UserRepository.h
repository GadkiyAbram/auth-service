#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <optional>
#include <unordered_map>
#include "UserDTO.h"
#include "../../database/DBConnection.h"

class UserRepository {
public:
    UserRepository(const DBConnection& dbConnection);

    bool createUser(const std::string& username, const std::string& password);
    bool userExists(const std::string& username) const;
    UserDTO getUser(const std::string& username) const;

private:
    const DBConnection& dbConnection;
    string generatePassword(int length);
    string hashPassword(const std::string& password);
};

#endif
