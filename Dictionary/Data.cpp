#include "Data.h"

Trie Data::trie;
string Data::filePath;

void Data::getData(){
    string myText;
    string myText1;
    string myText2 = "";
    string word;
    string meaning;
    string a;
    filePath = "C:\\Users\\Dell\\Desktop\\Data Structures and Algorithms\\Project\\Dictionary\\Dictionary\\DictionaryFile - Copy.txt";

    ifstream MyReadFile(filePath);

    while (getline (MyReadFile, myText)) {
        myText1 = myText;
        if(myText.length() < 10)
        myText.erase(remove_if(myText.begin(), myText.end(), ::isspace), myText.end());

        if(myText.length() == 0 || myText.length() == 1){
            a = ""; word = ""; meaning = "";
            bool wordFound = false;
            for(char i : myText2){
                if(! wordFound && i == ' '){
                    wordFound = true;
                    word = a;
                    a = "";
                }
                a += i;
            }
            meaning = a;
            trie.insertWord(word, meaning);
            myText2 = "";
        }else{
            myText2 += myText1;
        }
    }
    if(myText2 != ""){
        a = ""; word = ""; meaning = "";
        bool wordFound = false;
        for(char i : myText2){
            if(! wordFound && i == ' '){
                wordFound = true;
                word = a;
                a = "";
            }
            a += i;
        }
        meaning = a;
        trie.insertWord(word, meaning);
        myText2 = "";
    }

    // Close the file
    MyReadFile.close();
}

