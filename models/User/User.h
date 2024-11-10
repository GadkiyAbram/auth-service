#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <string>
#include <postgresql/libpq-fe.h>

using namespace std;

class User {
public:
    User();

    int getId();
    string getName() const;
    string getSurname() const;
    string getUsername() const;
    string getCreatedAt() const;
    string getUpdatedAt() const;
    int getAuthType() const;

    void setName(const string &name);
    void setSurname(const string &surname);
    void setUsername(const string &username);

    static void findByUsername(const string &username);

private:
    int id;
    string name;
    string surname;
    string username;
    string createdAt;
    string updatedAt;
    int authType;
};


#endif
