#include "UserDatabase.h"

UserDatabase::UserDatabase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\Dell\\Desktop\\Data Structures and Algorithms\\Project\\Dictionary\\Dictionary\\userdb.db");
    db.open();
}

void UserDatabase::createTable(){
    QSqlQuery query;
    query.exec("create table if not exists user(firstName string, lastName string, username string, password string, owner boolean)");
    query.clear();
}

void UserDatabase::close(){
    db.close();
}
