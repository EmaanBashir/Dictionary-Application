#ifndef SEARCH_USER_H
#define SEARCH_USER_H

#include <QWidget>

namespace Ui {
class search_user;
}

class search_user : public QWidget
{
    Q_OBJECT

public:
    explicit search_user(QWidget *parent = nullptr);
    ~search_user();
    void init();

private slots:


    void on_search_userBackButton_clicked();

    void on_search_userWordSearchButton_clicked();

    void on_search_userSentenceSearchButton_clicked();

private:
    Ui::search_user *ui;

signals:
    void gotoLogin();
};

#endif // SEARCH_USER_H
