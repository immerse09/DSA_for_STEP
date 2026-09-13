#include<iostream>
using namespace std;

// singly ll node structure
class Node{
    public:
    int data;
    Node*next;

    public:
   Node(int val){
    data = val;
    next = NULL;
   }

//    Destructor for Node
   ~Node(){
    cout << "~Node" << endl;
    if(next != NULL){
        delete next;
        next = NULL;
    }
   }
};

class List {
    Node* head;
    Node* tail;

    public:
    List(){
        head = NULL;
        tail = NULL;
    }

    // Destructor for list
    ~List(){
        cout << "~List" << endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        // Node* newNode(val); // static
        Node* newNode = new Node(val); // dynamic allocation

        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head; // also can, (*ptr).
            head = newNode;
        }
    }
};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // 1->2->3->null
    return 0;
}