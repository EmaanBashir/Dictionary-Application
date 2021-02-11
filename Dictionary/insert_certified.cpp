#include "insert_certified.h"
#include "ui_insert_certified.h"
#include "Data.h"
#include <QMessageBox>

using namespace std;

insert_certified::insert_certified(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insert_certified)
{
    ui->setupUi(this);
    init();
}

insert_certified::~insert_certified()
{
    delete ui;
}

void insert_certified::init(){
    ui->insert_certifiedLineEdit->setText("");
    ui->insert_certifiedTextEdit->setText("");
    ui->insert_certifiedErrorLabel->setText("");
}

void insert_certified::on_insert_certifiedNavSearch_clicked()
{
    emit gotoSearch_certified();
}

void insert_certified::on_insert_certifiedLogout_clicked()
{
    emit logout();
}

void insert_certified::on_insert_certifiedInsertButton_clicked()
{
    string word = ui->insert_certifiedLineEdit->text().toStdString();
    string meaning = ui->insert_certifiedTextEdit->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->insert_certifiedErrorLabel->setText("Invalid Input!");
    }else{
        for(char s : word){
            if(!((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))){
                ui->insert_certifiedErrorLabel->setText("Invalid Word!");
                return;
            }
        }
        Data::trie.insertWord(word, meaning);
        QMessageBox msgBox;
        msgBox.setText("The word has been inserted.");
        msgBox.exec();
        init();
    }

}
