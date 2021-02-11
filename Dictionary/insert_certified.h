#ifndef INSERT_CERTIFIED_H
#define INSERT_CERTIFIED_H

#include <QWidget>

namespace Ui {
class insert_certified;
}

class insert_certified : public QWidget
{
    Q_OBJECT

public:
    explicit insert_certified(QWidget *parent = nullptr);
    ~insert_certified();
    void init();

private:
    Ui::insert_certified *ui;

signals:
    void logout();
    void gotoSearch_certified();

private slots:
    void on_insert_certifiedNavSearch_clicked();
    void on_insert_certifiedLogout_clicked();
    void on_insert_certifiedInsertButton_clicked();
};

#endif // INSERT_CERTIFIED_H
