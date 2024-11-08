#include "JWTAuthEntity.h"

JWTAuthEntity::JWTAuthEntity(
        int userId,
        const std::string &login,
        const std::string &password,
        const std::string &version,
        const std::string &lastPassword,
        const std::string &createdAt,
        const std::string &updatedAt
        ) {}

int JWTAuthEntity::getUserId() const { return userId; }
const std::string &JWTAuthEntity::getPassword() const { return password; }
const std::string &JWTAuthEntity::getVersion() const { return version; }
const std::string &JWTAuthEntity::getLastPassword() const { return lastPassword; }
const std::string &JWTAuthEntity::getCreatedAt() const { return createdAt; }
const std::string &JWTAuthEntity::getUpdatedAt() const { return updatedAt; }

void JWTAuthEntity::setUpdatedAt(const std::string &updatedAt) {
    this->updatedAt = updatedAt;
}