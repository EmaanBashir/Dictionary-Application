#ifndef USERDATABASE_H
#define USERDATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriver>

using namespace std;

class UserDatabase {

public:
    QSqlDatabase db;
    UserDatabase();
    void createTable();
    void close();
};


#endif // USERDATABASE_H
