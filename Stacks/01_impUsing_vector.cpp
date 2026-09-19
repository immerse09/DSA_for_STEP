#include<iostream>
using namespace std;

// create stack using vector
class Stack {
    vector<int> vec;
    public:
    void push(int val) { // O(1)
         if(isEmpty()){
            cout << "Stack is empty.\n";
        }
        vec.push_back(val);
    }

    void pop() { // O(1)
        if(isEmpty()){
            cout << "Stack is empty.\n";
        }
        vec.pop_back();
    }

    int top(){ // O(1)
         if(isEmpty()){
            cout << "Stack is empty.\n";
            return -1;
        }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        cout << s.top() << " "; // infinite looop
        s.pop();
    }

    return 0;
}