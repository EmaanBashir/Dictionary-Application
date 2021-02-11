#include "Trie.h"
#include <fstream>

//Constructor
Trie::Trie(){
    root = newNode();
}

//struct for a node of the trie
struct Trie::TrieNode {
    TrieNode* children[26];
    bool isEndOfWord = false;
    string meaning;
};

//create a new node with null values
Trie::TrieNode* Trie::newNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    node->meaning = "";
    for (int i = 0; i < (int)sizeof(node->children) / sizeof(node->children[0]); i++) {
        node->children[i] = NULL;
    }
    return node;
}

//insertion
void Trie::insertWord(string word, string meaning) {
    insert(root, word, meaning);
}

//insertion at a specific node
void Trie::insert(TrieNode* node, string word, string meaning) {
    TrieNode* temp = node;
    int index;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] + 32;
        index = word[i] - 'a';
        if(index >=0 && index < 26){
        if (!temp->children[index])
            temp->children[index] = newNode();
        if (temp->children[index])
            temp = temp->children[index];
        }
        else {
            return;
        }
    }
    if (!temp->isEndOfWord) {
        temp->meaning = meaning;
        temp->isEndOfWord = true;
    }
}

//search
string Trie::getMeaning(string word) {
    TrieNode* node = search(root, word);
    if(! node){
        return "";
    }
    return node->meaning;
}

//search from a specific node
Trie::TrieNode* Trie::search(TrieNode* node, string word) {
    TrieNode* temp = node;
    int index;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] + 32;
        index = word[i] - 'a';
        if(index >=0 && index < 26){
        if (!temp->children[index])
            return NULL;
        temp = temp->children[index];
        }else{
            return NULL;
        }
    }
    if (temp->isEndOfWord) {
        return temp;
    }
    else {
        return NULL;
    }
}

//deletion
void Trie::deleteWord(string word) {
    remove(root, word, 0);
}

//removal of a node
Trie::TrieNode* Trie::remove(TrieNode* node, string word, int depth = 0)
{
    // check if tree is empty
    if (!node)
        return NULL;

    //check if last character of the word is being processed
    if (depth == word.size()) {

        if (node->isEndOfWord)
            node->isEndOfWord = false;

        // If given is not prefix of any other word
        if (!hasChildren(node)) {
            delete (node);
            node = NULL;
        }

        return node;
    }
    if (word[depth] >= 'A' && word[depth] <= 'Z')
        word[depth] = word[depth] + 32;

    // If not last character
    int index = word[depth] - 'a';
    if(index >=0 && index < 26){
        node->children[index] = remove(node->children[index], word, depth + 1);
    }else{
        return NULL;
    }
    // If root does not have any child
    if (!hasChildren(node) && node->isEndOfWord == false && node != root) {
        delete (node);
        node = NULL;
    }

    return node;
}

//method to check if a node has children
bool Trie::hasChildren(TrieNode* node) {
    for (TrieNode* trienode : node->children) {
        if (trienode)
            return true;
    }
    return false;
}

string Trie::displayAll() {
    char str[27];
    string x = "";
    string *text = &x;
    display(root, str, 0, text);
    return *text;
}

// function to display the content of Trie
void Trie::display(struct TrieNode* root, char str[], int level, string* text)
{
    if (root->isEndOfWord)
    {
        str[level] = '\0';
        *text =*text +  str + "  " + root->meaning + "\n\n";
    }

    int i;
    for (i = 0; i < alpha_size; i++)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1, text);
        }
    }
}

void Trie::updateWord(string oldWord, string newWord, string newMeaning){
    update(root, oldWord, newWord, newMeaning);
}

void Trie::update(TrieNode *root, string oldWord, string newWord, string newMeaning){
    if(oldWord == newWord){
        TrieNode *node = search(root, oldWord);
        node->meaning = newMeaning;
    }else{
        deleteWord(oldWord);
        insertWord(newWord, newMeaning);
    }
}

void Trie::writeToFile(string path){
      ofstream MyFile(path);
      MyFile << displayAll();
      MyFile.close();
}
