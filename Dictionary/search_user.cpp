#include "search_user.h"
#include "ui_search_user.h"
#include "Data.h"
#include <sstream>
#include <vector>
#include "sortingalgorithm.h"


using namespace std;

search_user::search_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_user)
{
    ui->setupUi(this);
    init();
}

void search_user::init(){
    ui->search_userWordLineEdit->setText("");
    ui->search_userSentenceLineEdit->setText("");
    ui->search_userWordMeaningBrowser->setText("");
    ui->search_userSentenceMeaningBrowser->setText("");
    ui->search_userWordErrorLabel->setText("");
    ui->search_userSentenceErrorLabel->setText("");
}

search_user::~search_user()
{
    delete ui;
}



void search_user::on_search_userBackButton_clicked()
{
    emit gotoLogin();
}

void search_user::on_search_userWordSearchButton_clicked()
{
    string word = ui->search_userWordLineEdit->text().toStdString();
    string meaning = Data::trie.getMeaning(word);
    if(word == ""){
        ui->search_userWordMeaningBrowser->setText("");
        ui->search_userWordErrorLabel->setText("Enter a word");
    }else if(meaning == ""){
        ui->search_userWordMeaningBrowser->setText("");
        ui->search_userWordErrorLabel->setText("Word not found!");
    }else{
        ui->search_userWordErrorLabel->setText("");
        ui->search_userWordMeaningBrowser->setText(QString::fromStdString(meaning));
    }
}

void search_user::on_search_userSentenceSearchButton_clicked()
{
    string sentence = ui->search_userSentenceLineEdit->toPlainText().toStdString();
    if(sentence == ""){
        ui->search_userSentenceErrorLabel->setText("Enter a Paragraph");
        ui->search_userSentenceMeaningBrowser->setText("");
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
    ui->search_userSentenceErrorLabel->setText("");
    ui->search_userSentenceMeaningBrowser->setText(QString::fromStdString(text));
}else{
        ui->search_userSentenceErrorLabel->setText("No difficult words found!");
        ui->search_userSentenceMeaningBrowser->setText("");
    }
}
}
