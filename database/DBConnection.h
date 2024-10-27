#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <postgresql/libpq-fe.h>
#include <string>
#include <sstream>

using namespace std;

struct DBConfig {
    const char* dbName;
    const char* user;
    const char* password;
    const char* host;
    int port;
};

class DBConnection {
public:
    DBConnection(const DBConnection&) = delete;
    DBConnection& operator=(const DBConnection) = delete;

    static DBConnection& getInstance();

    DBConnection(
        const string& dbName,
        const string& user,
        const string& password,
        const string& host,
        int port
        );

    ~DBConnection();

    void execute(const string& query);

    PGresult* query(const string& query) const;
    PGconn *connection;

    static DBConfig getDBConfig();

private:
    string connectionString;

    static void doExit(PGconn *connection);
};



#endif
