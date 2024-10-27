#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <optional>
#include <unordered_map>
#include "UserDTO.h"
#include "../../database/DBConnection.h"

class UserRepository {
public:
    UserRepository(const DBConnection& dbConnection);

    bool userExists(const std::string& username) const;
    UserDTO getUser(const std::string& username) const;

private:
    const DBConnection& dbConnection;
};

#endif
