#ifndef UPDATE_MAIN_H
#define UPDATE_MAIN_H

using namespace std;

#include <QWidget>

namespace Ui {
class update_main;
}

class update_main : public QWidget
{
    Q_OBJECT

public:
    static string oldWord;
    static string oldMeaning;

public:
    explicit update_main(QWidget *parent = nullptr);
    ~update_main();
    void init();

private:
    Ui::update_main *ui;

signals:
    void gotoSearch_main();
private slots:

    void on_update_mainBackButton_clicked();
    void on_update_mainUpdateButton_clicked();
};

#endif // UPDATE_MAIN_H
