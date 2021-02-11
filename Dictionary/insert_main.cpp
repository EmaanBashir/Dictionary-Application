#include "insert_main.h"
#include "ui_insert_main.h"
#include "Data.h"
#include <QMessageBox>

insert_main::insert_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insert_main)
{
    ui->setupUi(this);
    init();
}

insert_main::~insert_main()
{
    delete ui;
}

void insert_main::init(){
    ui->insert_mainLineEdit->setText("");
    ui->insert_mainTextEdit->setText("");
    ui->insert_mainErrorLabel->setText("");
}




void insert_main::on_insert_mainNavSearch_clicked()
{
    emit gotoSearch_main();
}

void insert_main::on_insert_mainCreate_2_clicked()
{
    emit gotoCreate();
}


void insert_main::on_insert_mainLogout_clicked()
{
    emit logout();
}

void insert_main::on_insert_mainInsertButton_clicked()
{
    string word = ui->insert_mainLineEdit->text().toStdString();
    string meaning = ui->insert_mainTextEdit->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->insert_mainErrorLabel->setText("Invalid Input!");
    }else{
        for(char s : word){
            if(!((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))){
                ui->insert_mainErrorLabel->setText("Invalid Word!");
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
