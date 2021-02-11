#include "update_main.h"
#include "ui_update_main.h"
#include "Data.h"
#include <QMessageBox>

string update_main::oldMeaning;
string update_main::oldWord;

update_main::update_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_main)
{
    ui->setupUi(this);
    init();
}

void update_main::init(){
    ui->update_mainLineEdit->setText(QString::fromStdString(oldWord));
    ui->update_mainTextEdit->setText(QString::fromStdString(oldMeaning));
    ui->update_mainWordErrorLabel->setText("");
}

update_main::~update_main()
{
    delete ui;
}


void update_main::on_update_mainBackButton_clicked()
{
    emit gotoSearch_main();
}

void update_main::on_update_mainUpdateButton_clicked()
{
    string word = ui->update_mainLineEdit->text().toStdString();
    string meaning = ui->update_mainTextEdit->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->update_mainWordErrorLabel->setText("Invalid Input!");
    }else{
        for(char s : word){
            if(!((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))){
                ui->update_mainWordErrorLabel->setText("Invalid Word!");
                return;
            }
        }
        Data::trie.updateWord(oldWord, word, meaning);
        QMessageBox msgBox;
        msgBox.setText("The word has been updated.");
        msgBox.exec();
        emit gotoSearch_main();
    }
}
