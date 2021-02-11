#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "UserDatabase.h"
#include <QTextEdit>
#include <iostream>
#include "Data.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Data data;
    data.getData();
    db.createTable();

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QMainWindow::showMaximized();

    ui->stackedWidget->insertWidget(0, &loginScreen);
    ui->stackedWidget->insertWidget(1, &search_certifiedScreen);
    ui->stackedWidget->insertWidget(2, &search_mainScreen);
    ui->stackedWidget->insertWidget(3, &createScreen);
    ui->stackedWidget->insertWidget(4, &insert_certifiedScreen);
    ui->stackedWidget->insertWidget(5, &insert_mainScreen);
    ui->stackedWidget->insertWidget(6, &search_userScreen);
    ui->stackedWidget->insertWidget(7, &update_certifiedScreen);
    ui->stackedWidget->insertWidget(8, &update_mainScreen);

    connect(&loginScreen, SIGNAL(certifiedUserLogin()), this, SLOT(gotoSearch_certifiedAction()));
    connect(&loginScreen, SIGNAL(mainLogin()), this, SLOT(gotoSearch_mainAction()));
    connect(&loginScreen, SIGNAL(gotoSearch_user()), this, SLOT(gotoSearch_userAction()));
    connect(&search_certifiedScreen, SIGNAL(logout()), this, SLOT(logoutAction()));
    connect(&search_certifiedScreen, SIGNAL(gotoInsert_certified()), this, SLOT(gotoInsert_certifiedAction()));
    connect(&search_certifiedScreen, SIGNAL(gotoUpdate_certified()), this, SLOT(gotoUpdate_certifiedAction()));
    connect(&update_certifiedScreen, SIGNAL(gotoSearch_certified()), this, SLOT(gotoSearch_certifiedAction()));
    connect(&insert_certifiedScreen, SIGNAL(gotoSearch_certified()), this, SLOT(gotoSearch_certifiedAction()));
    connect(&insert_certifiedScreen, SIGNAL(logout()), this, SLOT(logoutAction()));
    connect(&search_mainScreen, SIGNAL(logout()), this, SLOT(logoutAction()));
    connect(&search_mainScreen, SIGNAL(gotoInsert_main()), this, SLOT(gotoInsert_mainAction()));
    connect(&search_mainScreen, SIGNAL(gotoUpdate_main()), this, SLOT(gotoUpdate_mainAction()));
    connect(&search_mainScreen, SIGNAL(gotoCreate()), this, SLOT(gotoCreateAction()));
    connect(&update_mainScreen, SIGNAL(gotoSearch_main()), this, SLOT(gotoSearch_mainAction()));
    connect(&insert_mainScreen, SIGNAL(gotoSearch_main()), this, SLOT(gotoSearch_mainAction()));
    connect(&insert_mainScreen, SIGNAL(logout()), this, SLOT(logoutAction()));
    connect(&insert_mainScreen, SIGNAL(gotoCreate()), this, SLOT(gotoCreateAction()));
    connect(&search_userScreen, SIGNAL(gotoLogin()), this, SLOT(logoutAction()));
    connect(&createScreen, SIGNAL(logout()), this, SLOT(logoutAction()));
    connect(&createScreen, SIGNAL(gotoInsert_main()), this, SLOT(gotoInsert_mainAction()));
    connect(&createScreen, SIGNAL(gotoSearch_main()), this, SLOT(gotoSearch_mainAction()));

}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
    Data::trie.writeToFile(Data::filePath);
}

void MainWindow::logoutAction(){
    loginScreen.init();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::gotoSearch_certifiedAction(){
    search_certifiedScreen.init();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::gotoInsert_certifiedAction(){
    search_certifiedScreen.init();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::gotoUpdate_certifiedAction(){
    update_certifiedScreen.init();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::gotoSearch_mainAction(){
    search_mainScreen.init();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::gotoInsert_mainAction(){
    search_mainScreen.init();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::gotoUpdate_mainAction(){
    update_mainScreen.init();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::gotoCreateAction(){
    createScreen.init();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::gotoSearch_userAction(){
    search_userScreen.init();
    ui->stackedWidget->setCurrentIndex(6);
}

