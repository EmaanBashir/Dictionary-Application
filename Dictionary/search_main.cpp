#include "search_main.h"
#include "ui_search_main.h"
#include "Data.h"
#include "update_main.h"
#include <QMessageBox>
#include <sstream>
#include <vector>
#include "sortingalgorithm.h"

using namespace std;

search_main::search_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_main)
{
    ui->setupUi(this);
    init();
}

void search_main::init(){
    ui->search_mainWordLineEdit->setText("");
    ui->search_mainSentenceLineEdit->setText("");
    ui->search_mainWordMeaningBrowser->setText("");
    ui->search_mainSentenceMeaningBrowser->setText("");
    ui->search_mainWordErrorLabel->setText("");
    ui->search_mainSentenceErrorLabel->setText("");
}

search_main::~search_main()
{
    delete ui;
}

void search_main::on_search_mainCreateAccount_clicked()
{
    emit gotoCreate();
}

void search_main::on_search_mainNavInsert_clicked()
{
    emit gotoInsert_main();
}

void search_main::on_search_mainLogout_clicked()
{
    emit logout();
}

void search_main::on_search_mainWordSearchButton_2_clicked()
{
    string word = ui->search_mainWordLineEdit->text().toStdString();
    string meaning = Data::trie.getMeaning(word);
    if(word == ""){
        ui->search_mainWordMeaningBrowser->setText("");
        ui->search_mainWordErrorLabel->setText("Enter a word");
    }else if(meaning == ""){
        ui->search_mainWordMeaningBrowser->setText("");
        ui->search_mainWordErrorLabel->setText("Word not found!");
    }else{
        ui->search_mainWordErrorLabel->setText("");
        ui->search_mainWordMeaningBrowser->setText(QString::fromStdString(meaning));
    }
}

void search_main::on_search_mainUpdateButton_clicked()
{
    string word = ui->search_mainWordLineEdit->text().toStdString();
    string meaning = ui->search_mainWordMeaningBrowser->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->search_mainWordErrorLabel->setText("Invalid Input!");
    }else{
        update_main::oldWord = word;
        update_main::oldMeaning = meaning;
        emit gotoUpdate_main();
    }
}

void search_main::on_search_mainDeleteButton_clicked()
{
    string word = ui->search_mainWordLineEdit->text().toStdString();
    string meaning = ui->search_mainWordMeaningBrowser->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->search_mainWordErrorLabel->setText("Invalid Input!");
    }else{
        QMessageBox msgBox;
        msgBox.setText("Do you want to continue with the deletion?");
        msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:
              Data::trie.deleteWord(word);
              break;
        }
        init();
    }
}

void search_main::on_search_mainSentenceSearchButton_clicked()
{
    string sentence = ui->search_mainSentenceLineEdit->toPlainText().toStdString();
    if(sentence == ""){
        ui->search_mainSentenceErrorLabel->setText("Enter a Paragraph");
        ui->search_mainSentenceMeaningBrowser->setText("");
    }else{
    istringstream iss(sentence);
    vector<string> words;
    for(string s;iss>>s;){
        if(!((s.back() >= 'A' && s.back() <= 'Z') || (s.back() >= 'a' && s.back() <= 'z'))){
            s.pop_back();
        }
        if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z'))){
            s.erase(0);
        }
        words.push_back(s);
    }
    int n=words.size();
    SortingAlgorithm::quickSort(words, 0, n-1);
    string text = "", meaning, spaces;
    for(int i=0 ; i<n ; i++){
        spaces = "";
        if(i == 0 || ((i > 0) && (words[i] != words[i - 1]))){
            meaning = Data::trie.getMeaning(words[i]);
            if(meaning.length() > 0)
            text += (words[i] + ":\n\n" + Data::trie.getMeaning(words[i]) + "\n\n");
        }
    }
    if(text != ""){
    ui->search_mainSentenceErrorLabel->setText("");
    ui->search_mainSentenceMeaningBrowser->setText(QString::fromStdString(text));
}else{
        ui->search_mainSentenceErrorLabel->setText("No difficult words found!");
        ui->search_mainSentenceMeaningBrowser->setText("");
    }
}
}
