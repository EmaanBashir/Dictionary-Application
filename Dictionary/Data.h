#ifndef DATA_H
#define DATA_H
#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Data{

public:
    static Trie trie;
    static string filePath;
    void getData();
};

#endif // DATA_H
