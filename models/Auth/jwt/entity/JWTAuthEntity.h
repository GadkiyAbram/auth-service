#ifndef JWTAUTHENTITY_H
#define JWTAUTHENTITY_H

#include <string>

class JWTAuthEntity {
public:
    JWTAuthEntity(
            int userId,
            const std::string &login,
            const std::string &password,
            const std::string& version,
            const std::string& lastPassword,
            const std::string& createdAt,
            const std::string& updatedAt
            );

    int getUserId() const;
    const std::string &getLogin() const;
    const std::string &getPassword() const;
    const std::string &getVersion() const;
    const std::string &getLastPassword() const;
    const std::string &getCreatedAt() const;
    const std::string &getUpdatedAt() const;

    void setUpdatedAt(const std::string &updatedAt);

private:
    int userId;
    std::string login;
    std::string password;
    std::string version;
    std::string lastPassword;
    std::string createdAt;
    std::string updatedAt;
};

#endif
