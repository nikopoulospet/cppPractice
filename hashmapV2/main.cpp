#include <iostream>
#include <vector>
#include <array>
#include <math.h>

using namespace std;

struct hm_pair{
    int key;
    int val;
};

// hashmap properties -> stores (KEY VALUE PAIR)
// hm constructor
// hm destructor

// hm.empty
    //check if the hm is empty
// hm.size
    // return number of keys in hm
// hm.insert
    // insert value at a specified key
// hm.at
    // returns reference to first entry of hashed values vector
// hm.find
    // return reference to vector of hashed values
// hm.contains
    // checks if key contains any values
// hm.count

class hash_map {
    public:
        hash_map(int size){
            this->size = size;
            occupied = 0;
            map = new vector<struct hm_pair>*[size];
            for(int i=0; i<size; i++){
                map[i] = new vector<struct hm_pair>;
            }
        }

        void insert(struct hm_pair ins){
            occupied++;
            if(occupied>size/2){
                resize_map();
            }
            int index = hash_func(ins.key, size);
            map[index]->push_back(ins);
        }

        int* at(int key){
            int index = hash_func(key, size);
            for(int i=0;i<map[index]->size();i++){
                if(map[index]->at(i).key == key){
                    return &map[index]->at(i).val;
                }
            }
            return NULL;
        }

        bool in(int key){
            int index = hash_func(key, size);
            for(int i=0;i<map[index]->size();i++){
                if(map[index]->at(i).key == key){
                    return true;
                }
            }
            return false;
        }

        vector<struct hm_pair>* find(int key){
            int index = hash_func(key, size);
            return map[index];
        }

        int occupancy(){
            return occupied;
        }

        bool empty(){
            for(int i=0;i<this->size;i++){
                if(!map[i]->empty()){
                    return false;
                }
            }
            return true;
        }


    private:
        int size;
        unsigned int occupied;
        vector<struct hm_pair> **map;

        int hash_func(int key, int size){
            int hsh = floor(size*(key*0.71));
            return hsh%size;
        }

        void resize_map(){
            int new_size = size*2;
            cout << "resizing map to: " << new_size << endl;

            // allocate new map on the heap
            vector<struct hm_pair> **newMap = new vector<struct hm_pair>*[new_size];
            for(int i=0;i<new_size;i++){
                newMap[i] = new vector<struct hm_pair>;
            }

            // rehash into new map
            struct hm_pair* temp;
            for(int i=0;i<size;i++){
                for(int ii=0;i<map[i]->size();i++){
                    temp = &map[i]->at(ii);
                    int index = hash_func(temp->key,new_size);
                    newMap[index]->push_back(*temp);
                }
            }

            // delete old map memory
            delete [] map;

            map = newMap;
            size = new_size;
        }


};


int main() {
    hash_map hm(1);
    hm.insert({213,23});
    int *temp = hm.at(213);
    cout << *temp << endl;

    //create vector ptr array, only create a vector once index is accessed

    return 0;
}
