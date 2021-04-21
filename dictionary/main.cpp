#include <iostream>
#include <memory>
#include "dict.h"

int add(int a, int b){
    std::unique_ptr<int> ans (new int);
    *ans = a+b;
    return *ans;
}

int main() {
    Hashmap hm;
    hm.add_el(112,12);
    hm.add_el(10, 3);

    std::cout << hm.access_el(112)->size() << std::endl;
    return 0;
}
