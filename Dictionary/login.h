#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <QWidget>

using namespace std;

namespace Ui {
class login;
}
class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool isEmpty(string username, string password);
    bool check(string username, string password, bool *main);
    void init();

private:
    Ui::login *ui;

signals:
    void certifiedUserLogin();
    void mainLogin();
    void gotoSearch_user();

private slots:
    void on_loginButton_clicked();

    void on_guestButton_clicked();
};

#endif // LOGIN_H
