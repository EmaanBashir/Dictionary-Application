#include "search_certified.h"
#include "ui_search_certified.h"
#include "Data.h"
#include <sstream>
#include <vector>
#include "sortingalgorithm.h"
#include "update_certified.h"
#include <QMessageBox>

using namespace std;

search_certified::search_certified(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_certified)
{
    ui->setupUi(this);
    init();
}

void search_certified::init(){
    ui->search_certifiedWordLineEdit->setText("");
    ui->search_certifiedSentenceLineEdit->setText("");
    ui->search_certifiedWordMeaningBrowser->setText("");
    ui->search_certifiedSentenceMeaningBrowser->setText("");
    ui->search_certifiedWordErrorLabel->setText("");
    ui->search_certifiedSentenceErrorLabel->setText("");
}

search_certified::~search_certified()
{
    delete ui;
}

void search_certified::on_search_certifiedLogout_clicked()
{
    emit logout();
}

void search_certified::on_search_certifiedWordSearchButton_2_clicked()
{
    string word = ui->search_certifiedWordLineEdit->text().toStdString();
    string meaning = Data::trie.getMeaning(word);
    if(word == ""){
        ui->search_certifiedWordMeaningBrowser->setText("");
        ui->search_certifiedWordErrorLabel->setText("Enter a word");
    }else if(meaning == ""){
        ui->search_certifiedWordMeaningBrowser->setText("");
        ui->search_certifiedWordErrorLabel->setText("Word not found!");
    }else{
        ui->search_certifiedWordErrorLabel->setText("");
        ui->search_certifiedWordMeaningBrowser->setText(QString::fromStdString(meaning));
    }
}

void search_certified::on_search_certifiedNavInsert_clicked()
{
    emit gotoInsert_certified();
}

void search_certified::on_search_certifiedSentenceSearchButton_clicked()
{
    string sentence = ui->search_certifiedSentenceLineEdit->toPlainText().toStdString();
    if(sentence == ""){
        ui->search_certifiedSentenceErrorLabel->setText("Enter a Paragraph");
        ui->search_certifiedSentenceMeaningBrowser->setText("");
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
    ui->search_certifiedSentenceErrorLabel->setText("");
    ui->search_certifiedSentenceMeaningBrowser->setText(QString::fromStdString(text));
}else{
        ui->search_certifiedSentenceErrorLabel->setText("No difficult words found!");
        ui->search_certifiedSentenceMeaningBrowser->setText("");
    }
}
}

void search_certified::on_search_certifiedUpdateButton_clicked()
{
    string word = ui->search_certifiedWordLineEdit->text().toStdString();
    string meaning = ui->search_certifiedWordMeaningBrowser->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->search_certifiedWordErrorLabel->setText("Invalid Input!");
    }else{
        update_certified::oldWord = word;
        update_certified::oldMeaning = meaning;
        emit gotoUpdate_certified();
    }
}

void search_certified::on_search_certifiedDeleteButton_clicked()
{
    string word = ui->search_certifiedWordLineEdit->text().toStdString();
    string meaning = ui->search_certifiedWordMeaningBrowser->toPlainText().toStdString();
    if(word == "" || meaning == ""){
        ui->search_certifiedWordErrorLabel->setText("Invalid Input!");
    }else{
        QMessageBox msgBox;
        msgBox.setText("Do you want to delete the word?");
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
