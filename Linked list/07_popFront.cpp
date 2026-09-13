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
};

class List {
    Node* head;
    Node* tail;

    public:
    List(){
        head = NULL;
        tail = NULL;
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

        void pop_front(){
            if(head == NULL){
                cout << "LL is empty\n";
                return;
            }
            Node* temp = head;
            head = head->next;

            temp->next = NULL;
            delete temp;
        
    }
};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList(); // 1->2->3->null
    
    ll.pop_front();
    ll.printList(); // 2->3->null
    return 0;
}