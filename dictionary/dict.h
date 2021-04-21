//
// Created by peter on 4/3/21.
//

#ifndef DICTIONARY_DICT_H
#define DICTIONARY_DICT_H
#include <functional>
#include <iostream>
#include <vector>

class Hashmap{
public:
    Hashmap();
    void add_el(int key, int val);
    std::vector<int> *access_el(int key);
    void remove_el(int key);

private:
    std::vector<int> *map;
    int res;
    int stored;

    int hash_val(int val);
    void expandArray();
};


#endif //DICTIONARY_DICT_H
