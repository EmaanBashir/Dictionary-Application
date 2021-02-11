#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "search_certified.h"
#include "search_main.h"
#include "insert_certified.h"
#include "insert_main.h"
#include "create.h"
#include "search_user.h"
#include "update_certified.h"
#include "update_main.h"
#include "UserDatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserDatabase db;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    login loginScreen;
    search_certified search_certifiedScreen;
    search_main search_mainScreen;
    class create createScreen;
    insert_certified insert_certifiedScreen;
    insert_main insert_mainScreen;
    search_user search_userScreen;
    update_certified update_certifiedScreen;
    update_main update_mainScreen;

private slots:
    void logoutAction();
    void gotoSearch_certifiedAction();
    void gotoInsert_certifiedAction();
    void gotoUpdate_certifiedAction();
    void gotoSearch_mainAction();
    void gotoInsert_mainAction();
    void gotoUpdate_mainAction();
    void gotoCreateAction();
    void gotoSearch_userAction();
};
#endif // MAINWINDOW_H
