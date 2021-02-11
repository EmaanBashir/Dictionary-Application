#include "login.h"
#include "ui_login.h"
#include "UserDatabase.h"
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QCompleter>
using namespace std;
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    init();
}

login::~login()
{
    delete ui;
}

void login::init(){
    ui->loginErrorLabel->setText("");
    ui->usernameLineEdit->setText("");
    ui->passwordLineEdit->setText("");
}

void login::on_loginButton_clicked()
{
    string username = ui->usernameLineEdit->text().toStdString();
    string password = ui->passwordLineEdit->text().toStdString();
    bool mainUser;
    string error;
            if(isEmpty(username, password)) {
                ui->loginErrorLabel->setText("Required Fields are Empty!");
                return;
            }else if(! check(username, password, &mainUser)) {
                ui->loginErrorLabel->setText("Incorrect username or password!");
            }else {
                if(mainUser){
                    emit mainLogin();
                }else{
                    emit certifiedUserLogin();
                }
            }
}

bool login::isEmpty(string username, string password){
    return username == "" || password == "";
}

bool login::check(string username, string password, bool *main){
    QSqlQuery query;
    string str = "select owner from user where username = \"" + username + "\" and password = \"" + password + "\"";
    query.exec(QString::fromStdString(str));
    if(query.next()){
        if(query.value(0).toBool()){
            *main = true;
        }else{
            *main = false;
        }
        query.clear();
        return true;
    }else{
        query.clear();
        return false;
    }
}


void login::on_guestButton_clicked()
{
    emit gotoSearch_user();
}
