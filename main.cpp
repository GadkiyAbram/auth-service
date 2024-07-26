#include <chrono>
#include <iostream>
#include <thread>
#include "database/DBConnection.h"
#include "server/Server.h"

using namespace std;

void keepAlive() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int checkConnection() {
    const DBConfig dbConfig = DBConnection::getDBConfig();

    const DBConnection& dbConnection = DBConnection::getInstance(
        dbConfig.dbName,
        dbConfig.user,
        dbConfig.password,
        dbConfig.host,
        dbConfig.port
        );

    if (PQstatus(dbConnection.connection) != CONNECTION_OK) {
        cerr << "Connection failed" << PQerrorMessage(dbConnection.connection) << endl;
    }

    cout << "Connection successful" << endl;

    return 0;
}

int main() {
    cout << "\nHello, this is the Dockerized CPP application!\n\n";

    checkConnection();

    Server server(8080);

    thread server_thread(&Server::launch, server);
    server_thread.detach();

    keepAlive();

    return 0;
}
