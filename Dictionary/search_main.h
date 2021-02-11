#ifndef SEARCH_MAIN_H
#define SEARCH_MAIN_H

#include <QWidget>

namespace Ui {
class search_main;
}

class search_main : public QWidget
{
    Q_OBJECT

public:
    explicit search_main(QWidget *parent = nullptr);
    ~search_main();
    void init();

private:
    Ui::search_main *ui;

signals:
    void logout();
    void gotoInsert_main();
    void gotoUpdate_main();
    void gotoCreate();

private slots:
    void on_search_mainCreateAccount_clicked();
    void on_search_mainNavInsert_clicked();
    void on_search_mainLogout_clicked();
    void on_search_mainWordSearchButton_2_clicked();
    void on_search_mainUpdateButton_clicked();
    void on_search_mainDeleteButton_clicked();
    void on_search_mainSentenceSearchButton_clicked();
};

#endif // SEARCH_MAIN_H
