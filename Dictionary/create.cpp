#include "create.h"
#include "ui_create.h"
#include "UserDatabase.h"
#include <QMessageBox>

using namespace std;

create::create(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create)
{
    ui->setupUi(this);
    init();
}

void create::init(){
    ui->createFirstNameLineEdit->setText("");
    ui->createLastNameLineEdit->setText("");
    ui->createUsernameLineEdit->setText("");
    ui->createPasswordLineEdit->setText("");
    ui->createConfirmPasswordLineEdit->setText("");
    ui->createErrorLabel->setText("");
}

create::~create()
{
    delete ui;
}

void create::on_createNavSearch_clicked()
{
    emit gotoSearch_main();
}

void create::on_createNavInsert_clicked()
{
    emit gotoInsert_main();
}

void create::on_createLogout_clicked()
{
    emit logout();
}

void create::on_createCreateButton_clicked()
{
    string firstName = ui->createFirstNameLineEdit->text().toStdString();
    string lastName = ui->createLastNameLineEdit->text().toStdString();
    string username = ui->createUsernameLineEdit->text().toStdString();
    string password = ui->createPasswordLineEdit->text().toStdString();
    string confirmPassword = ui->createConfirmPasswordLineEdit->text().toStdString();
    if(firstName == "" || lastName == "" || username == "" || password == "" || confirmPassword == ""){
        ui->createErrorLabel->setText("Required Fields are Empty!");
    }else if(! isValid(username)){
        ui->createErrorLabel->setText("User already exists!");
    }else if(password != confirmPassword){
        ui->createErrorLabel->setText("Passwords do not match!");
    }else if(password.length() < 8){
        ui->createErrorLabel->setText("Password should have atleast 8 characters!");
    }else{
        insert(username, lastName, username, password);
        QMessageBox msgBox;
        msgBox.setText("Account has been created.");
        msgBox.exec();
        init();
    }
}

void create::insert(string firstName, string lastName, string username, string password){
    QSqlQuery query;
    string s = "insert into user values(\"" + firstName + "\",\"" + lastName + "\",\"" +
            username + "\",\"" + password + "\",false)";
    query.exec(QString::fromStdString(s));
    query.clear();
}

bool create::isValid(string username){
    QSqlQuery query;
    string s = "select * from user where username = \"" + username + "\"";
    query.exec(QString::fromStdString(s));
    if(!query.next()){
        query.clear();
        return true;
    }
    query.clear();
    return false;
}

