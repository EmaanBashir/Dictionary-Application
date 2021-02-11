#ifndef CREATE_H
#define CREATE_H

using namespace std;

#include <QWidget>

namespace Ui {
class create;
}

class create : public QWidget
{
    Q_OBJECT

public:
    explicit create(QWidget *parent = nullptr);
    ~create();
    void init();

private:
    Ui::create *ui;

signals:
    void logout();
    void gotoSearch_main();
    void gotoInsert_main();
private slots:
    void on_createNavSearch_clicked();
    void on_createNavInsert_clicked();
    void on_createLogout_clicked();
    void on_createCreateButton_clicked();
    void insert(string firstName, string lastName, string username, string password);
    bool isValid(string username);
};

#endif // CREATE_H
