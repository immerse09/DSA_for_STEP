#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

//  create stack using Linked list
template<class T>
class Stack {
    list<T> ll;

    public:
    void push(T val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    T top(){
        return ll.front();
    }

    bool isEmpty(){
        return ll.size() == 0;
    }
};



int main(){
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout << s.top() << " "; // 1, 2, 3
        s.pop();
    }
    cout << endl;
    return 0;
}

// Qs) without using <list> STL
// i.e without #include<list>
// just in raw formate

// create stack using linked list in raw process

template<class T>
class Node {
public:
    T data;
    Node* next;
    
    Node(T val){
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack{
    
    Node<T>* head;
public:
    // Qs) without using <list> ST
    stack(){
        head = NULL;
    }

    void push(T val){
        // push-front
        Node<T>* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        // pop-front
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top(){
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

// Note: we change in class but not in main func.
// coz stack func. alwys will be same
int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout << s.top() << " "; //
    }
}



// STL stack
#include<Stack>

int main(){
    // STL stack
    stack<int> s;

     s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}