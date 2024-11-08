#ifndef USER_DTO_H
#define USER_DTO_H

#include <string>

using namespace std;

class UserDTO {
public:
    UserDTO(
            const std::string& username,
            const std::string& password,
            const int &authType
    );

    std::string getUsername() const;
    std::string getPassword() const;
    int getAuthType() const;

private:
    std::string username;
    std::string password;
    int authType;
};

#endif
