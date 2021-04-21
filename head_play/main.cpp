#include <iostream>
using namespace std;

// how do things get malloced to the heap and when is it needed??
// when do i need this? lets create a graph

struct g_node{
    int val;
    struct g_node *next;
};

int main() {
    /*
    int G = 0;
    G = !G;
    cout << G << endl;



    int el = 5; // stack
    int *el_h = new int; // heap
    *el_h = 5;  // deref assignment


    struct g_node *head = new g_node;
    head->val = 10;
    head->next = new g_node[3];

    struct g_node *node;

    node = head->next;

    for(int i=0;i<3;i++){
        node->val = 10*i;
        cout << "address " << node << endl;
        cout << "value " << node->val << endl;

        node++;
    }
    head->next->val = 10;
    */


    // pointer arithmtic and iteration
    int arr[3] = {10,20,30};
    int *ptr;
    ptr = arr; //ptr address is first address of array

    for(int i=0;i<3;i++){
        cout << "address " << ptr << endl;
        cout << "value " << *ptr << endl;
        ptr++;

    }

    int *d1_arr = new int[10]; // arr size of 10
    int **d2_arr = new int*[10];
/*
    int temp = 1;
    cout << sizeof(int) <<endl;
    cout << (temp&1) << endl;
    int t = temp << 1;
    cout << t << endl;
    int u = temp >> 1;
    cout << u << endl; */
    return 0;
}
