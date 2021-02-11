#ifndef SEARCH_CERTIFIED_H
#define SEARCH_CERTIFIED_H
#include <string>
#include <QWidget>

using namespace std;

namespace Ui {
class search_certified;
}

class search_certified : public QWidget
{
    Q_OBJECT

public:
    explicit search_certified(QWidget *parent = nullptr);
    ~search_certified();
    void init();

private slots:
    void on_search_certifiedLogout_clicked();

    void on_search_certifiedWordSearchButton_2_clicked();

    void on_search_certifiedNavInsert_clicked();

    void on_search_certifiedSentenceSearchButton_clicked();

    void on_search_certifiedUpdateButton_clicked();

    void on_search_certifiedDeleteButton_clicked();

private:
    Ui::search_certified *ui;

signals:
    void logout();
    void gotoInsert_certified();
    void gotoUpdate_certified();
};

#endif // SEARCH_CERTIFIED_H
