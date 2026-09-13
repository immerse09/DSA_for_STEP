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
    }

    // func to for adding node at back
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;
        
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insertInMiddle(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout << "position is INVALID\n";
                return;
            }
            temp = temp->next;
        }

        // temp is now at pos-1 i.e prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);

    ll.insertInMiddle(100, 2);
    ll.printList(); // 1->2->100->3->4->5->null
        return 0;
}