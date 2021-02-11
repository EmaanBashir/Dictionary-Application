#include "update_certified.h"
#include "ui_update_certified.h"
#include "Data.h"
#include <QMessageBox>

string update_certified::oldMeaning;
string update_certified::oldWord;

update_certified::update_certified(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_certified)
{
    ui->setupUi(this);
    init();
}

update_certified::~update_certified()
{
    delete ui;
}

void update_certified::init(){
    ui->update_certifiedLineEdit->setText(QString::fromStdString(oldWord));
    ui->update_certifiedTextEdit->setText(QString::fromStdString(oldMeaning));
    ui->search_certifiedWordErrorLabel->setText("");
}

void update_certified::on_update_certifiedUpdateButton_clicked()
{
    string word = ui->update_certifiedLineEdit->text().toStdString();
    string meaning = ui->update_certifiedTextEdit->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->search_certifiedWordErrorLabel->setText("Invalid Input!");
    }else{
        for(char s : word){
            if(!((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))){
                ui->search_certifiedWordErrorLabel->setText("Invalid Word!");
                return;
            }
        }
        Data::trie.updateWord(oldWord, word, meaning);
        QMessageBox msgBox;
        msgBox.setText("The word has been updated.");
        msgBox.exec();
        emit gotoSearch_certified();
    }
}

void update_certified::on_update_certifiedBackButton_clicked()
{
    emit gotoSearch_certified();
}

