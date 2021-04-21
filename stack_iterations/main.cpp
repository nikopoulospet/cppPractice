#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> sort(vector<int> *l1, vector<int> *l2){
    int p1 = 0;
    int p2 = 0;
    vector<int> temp;

    while(p1 < l1->size() and p2 < l2->size()){
        // merge here
        if(l1[p1] < l2[p2]){
            //merge p1
            temp.push_back(l1->at(p1));
            p1++;
        }else{
            temp.push_back(l2->at(p2));
            p2++;
        }
    }


    for(int i=p2;i<l2->size();i++){
        temp.push_back(l2->at(i));
    }

    for(int i=p1;i<l1->size();i++){
        temp.push_back(l1->at(i));
    }

    return temp;

}

int main() {
    vector<int> temp({1,3,2,4,5,6});
    deque<vector<int>> stack;

    for(int i=0;i<temp.size();i++){
        stack.push_back(vector<int>({temp[i]}));
    }

    while(stack.size() != 1){
        vector<int> *p1 = &stack.at(0);
        vector<int> *p2 = &stack.at(1);
        stack.push_back(sort(p1,p2));
        stack.pop_front();
        stack.pop_front();
    }

    for(int i=0;i<stack.front().size();i++){
        std::cout << stack.front().at(i) << std::endl;
    }
    return 0;
}
