#ifndef UPDATE_CERTIFIED_H
#define UPDATE_CERTIFIED_H

#include <QWidget>

using namespace std;

namespace Ui {
class update_certified;
}

class update_certified : public QWidget
{
    Q_OBJECT

public:
    static string oldWord;
    static string oldMeaning;

public:
    explicit update_certified(QWidget *parent = nullptr);
    ~update_certified();
    void init();

private slots:
    void on_update_certifiedUpdateButton_clicked();

    void on_update_certifiedBackButton_clicked();

private:
    Ui::update_certified *ui;

signals:
    void gotoSearch_certified();
};

#endif // UPDATE_CERTIFIED_H
