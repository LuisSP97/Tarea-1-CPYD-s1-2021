#ifndef CODIGO_SPLIT_H
#define CODIGO_SPLIT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string split(string word){
    for (int i = 0; i < 2; ++i) {
        word.erase(remove(word.begin(), word.end(),'"'));
    }
    return word;
}

#endif //CODIGO_SPLIT_H
