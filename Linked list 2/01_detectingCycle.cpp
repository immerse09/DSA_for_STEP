#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

  
    Node(int val){
        // data = val;
        this->data = data;
        next = NULL;
}
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head= newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
}

void printList(Node* head{
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// function to detecting cycle 
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Cycle exists\n";
        }
    }

    cout << "Cycle doesn't exists\n";
    return false;
}

int main(){
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // 1->2->3->4

    // for infinite list
    ll.tail->next = ll.head;

    isCycle(ll.head);
}