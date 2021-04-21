#include <iostream>

struct Node{
    int data;
    Node *next;
};

class LinkedList
{
public:
    LinkedList(){ // constructor
        head = nullptr;
        tail = nullptr;
    }

    //adds elements to end of list
    void add_element(int val){
        Node *temp = new Node;
        temp->data = val;
        temp->next = nullptr;

        if(head == nullptr) {
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    //removes element from end of the list
    void remove_element(){
        if(head == nullptr){
            return;
        }

        Node *itr = head;
        while(itr->next != tail){
            itr = itr->next;
        }
        itr->next = nullptr;
        tail = itr;
    }

    void remove_by_data(int val){
        if(head == nullptr){
            return;
        }

        Node *itr = head;
        while(itr->next != nullptr) {
            if (itr->next->data == val) {
                //remove next block
                itr->next = itr->next->next;
                return;
            }
            itr = itr->next;
        }
    }

    //print elements in the list
    void print_elements(){
        Node *itr = head;
        while(itr != nullptr) {
            std::cout << itr->data << std::endl;
            itr = itr->next;
        }
    }

private:
    Node *head;
    Node *tail;

// adds elements to end of list list
// removes elements from end of list
// print elements in list

};

int main() {
    LinkedList ll;

    for(int i=0;i<10;i++) {
        ll.add_element(i);
    }
    ll.add_element(5);
    ll.remove_by_data(9);
    ll.print_elements();

    if(nullptr==nullptr){
        std::cout << "Hello, World!" << std::endl;
    }
    return 0;
}
