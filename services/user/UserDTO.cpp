#include "UserDTO.h"

UserDTO::UserDTO(const std::string &username, const std::string &password)
    : username(username), password(password) {}

std::string UserDTO::getUsername() const {
    return username;
}

std::string UserDTO::getPassword() const {
    return password;
}