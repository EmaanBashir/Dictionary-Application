#ifndef INSERT_MAIN_H
#define INSERT_MAIN_H

#include <QWidget>

namespace Ui {
class insert_main;
}

class insert_main : public QWidget
{
    Q_OBJECT

public:
    explicit insert_main(QWidget *parent = nullptr);
    ~insert_main();
    void init();

private:
    Ui::insert_main *ui;

signals:
    void logout();
    void gotoSearch_main();
    void gotoCreate();
private slots:

    void on_insert_mainNavSearch_clicked();
    void on_insert_mainCreate_2_clicked();
    void on_insert_mainLogout_clicked();
    void on_insert_mainInsertButton_clicked();
};

#endif // INSERT_MAIN_H
