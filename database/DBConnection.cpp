#include "DBConnection.h"
#include <iostream>
#include <postgresql/libpq-fe.h>

#include "../constants/db/DBConstants.hpp"

using namespace std;

DBConnection::DBConnection(
    const string &dbName,
    const string &user,
    const string &password,
    const string &host,
    const int port
    ) {
    connectionString = "dbname=" + dbName + " user=" + user + " password=" + password + " host=" + host + " port=" + to_string(port);
    connection = PQconnectdb(connectionString.c_str());

    if (PQstatus(connection) != CONNECTION_OK) {
        cerr << "Connection to database failed: " << PQerrorMessage(connection) << endl;
        doExit(connection);
    } else {
        cout << "Opened database successfully: " << PQdb(connection) << endl;
    }
}

DBConnection::~DBConnection() {
    PQfinish(connection);
}

void DBConnection::doExit(PGconn *connection) {
    PQfinish(connection);

    exit(1);
}

DBConnection& DBConnection::getInstance() {
    const DBConfig dbConfig = getDBConfig();

    static DBConnection instance(
            dbConfig.dbName,
            dbConfig.user,
            dbConfig.password,
            dbConfig.host,
            dbConfig.port
            );

    return instance;
}

PGresult* DBConnection::query(const string& query) const {
    PGresult *result = PQexec(connection, query.c_str());
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        std::cerr << "Query failed: " << PQerrorMessage(connection) << endl;
        PQclear(result);
        doExit(connection);
    }
    return result;
}

bool DBConnection::insert(const string &query) const {
    PGresult* result = PQexec(connection, query.c_str());

    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        std::cerr << "Insert failed: " << PQerrorMessage(connection) << std::endl;
        PQclear(result);

        return false;
    }

    PQclear(result);

    return true;;
}

DBConfig DBConnection::getDBConfig() {
    const char* dbName = getenv("POSTGRES_DB");
    const char* user = getenv("POSTGRES_USER");
    const char* password = getenv("POSTGRES_PASSWORD");
    const char* host = getenv("POSTGRES_HOST");
    const char* portString = getenv("POSTGRES_PORT");

    const int port = (portString != nullptr) ? stoi(portString) : DBConstants::PORT_DEFAULT;

    return {dbName, user, password, host, port};
}