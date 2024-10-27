#ifndef USER_DTO_H
#define USER_DTO_H

#include <string>

using namespace std;

class UserDTO {
public:
    UserDTO(const std::string& username, const std::string& password);

    std::string getUsername() const;
    std::string getPassword() const;

private:
    std::string username;
    std::string password;
};

#endif
