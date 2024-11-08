#include "UserDTO.h"

UserDTO::UserDTO(
        const std::string &username,
        const std::string &password,
        const int &authType
        )
    : username(username), password(password), authType(authType) {}

std::string UserDTO::getUsername() const { return username; }
std::string UserDTO::getPassword() const { return password; }
int UserDTO::getAuthType() const { return authType; }