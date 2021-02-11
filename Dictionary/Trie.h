#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#define alpha_size 26

using namespace std;

//Datastructure Trie
class Trie {
//private methods
private:
    struct TrieNode;
    TrieNode* newNode();
    TrieNode* root;

//public methods
public:
    Trie();

    void insert(TrieNode* node, string word, string meaning);
    void insertWord(string word, string meaning);
    string getMeaning(string word);
    TrieNode* search(TrieNode* node, string word);
    void deleteWord(string word);
    TrieNode* remove(TrieNode* node, string word, int depth);
    bool hasChildren(TrieNode* node);
    string displayAll();
    void display(TrieNode* root, char str[], int level, string* text);
    void update(TrieNode* root, string oldWord, string newWord, string newMeaning);
    void updateWord(string oldWord, string newWord, string newMeaning);
    void writeToFile(string path);
};

#endif // TRIE_H
