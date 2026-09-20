#include<iostream>
using namespace std;

// nodes of linked list
class Node {
public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = NULL;
    }
    
    void push(int data){ //O(1)
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    void pop(){ //O(1)
        if(empty()){
            cout << "queue is empty\n";
        }
       Node* temp = head;
       head = head->next;
        delete temp;
    }

   
    void front(){ //O(1)
         if(empty()){
            cout << "queue is empty\n";
            return -1;
        }
        return head->data;
    }

     bool empty(){ //O(1)
        return head == NULL;
    }

};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}

