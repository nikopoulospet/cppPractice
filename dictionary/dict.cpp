//
// Created by peter on 4/3/21.
//
#include "dict.h"

// hashmap properties
// define types
//## PUBLIC
// add elements
// access items
// remove an item
//## PRIVATE
// resize map
// handle clashing
// hash()


Hashmap::Hashmap(){
    std::cout<<"created hashmap"<<std::endl;
    res = 10;
    *map = new std::vector<int>;
    stored = 0;
}

void Hashmap::add_el(int key, int val){
    stored++;
    if(stored>=res/2){
        res = res*10;
        Hashmap::expandArray();
    }
    map[hash_val(key)%(res)]->push_back(val);
}

std::vector<int> *Hashmap::access_el(int key){
    int index = hash_val(key)%(res);
    if (map[index]->size()==0){
        return nullptr;
    }
    return map[index];
}

void Hashmap::remove_el(int key){
    int index = hash_val(key)%(res);
    stored = stored - map[index]->size();
    map[index]->clear();
}

int Hashmap::hash_val(int val){
    std::hash<int> ptr_hash;
    return ptr_hash(val);
}

void Hashmap::expandArray(){
    std::cout<<"expanded hashmap"<<std::endl;
    int temp = 1;
}
