#include <iostream>
#include "unordered_map"
#include "string.h"


struct node{
    int val;
    int numChild;
    struct node** children;
};

node* createNode(int val, int numChild){
    struct node *N = new node;
    N->val = val;
    N->numChild = numChild;
    N->children = new node*[numChild];
    return N;
}


int main() {
    struct node *root = createNode(1,5);
    struct node** temp = root->children;
    delete [] root;

    struct node *test;

    test = temp[6];


    std::unordered_map<std::string, int> map;
    map.insert({"hello",1});
    map.insert({"howdy",2});
    map.insert({"howdyy",3});
    map.insert({"hhowdy",4});
    map.insert({"howwwdy",5});

    std::unordered_map<std::string,int>::iterator itr = map.begin();

    while(itr != map.end()){
        std::cout << itr->second << std::endl;
        itr++;
    }


    int x = map["howdy"];
    int y = map.at("howdy");



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
