#include<iostream>
#include<vector>
#include<string>
using namespace std;


// create stack using vector
template<class T>
class Stack {
    vector<T> vec;
    public:
    void push(T val) { // O(1)
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

    T top(){ // O(1)
        //  if(isEmpty()){
        //     cout << "Stack is empty.\n";
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    
    // ab apan kisi type ke data type ka stack bana sakte hai
    // only by changing in main funcion
    
    // Stack<char> s;

    // s.push('a');
    // s.push('b');
    // s.push('c');
    // s.push('d');

    Stack<string> s;

    s.push("learn");
    s.push("coding");
    s.push("apnacollege");
    s.push("Happy");

    while(!s.isEmpty()){
        cout << s.top() << " "; // infinite looop
        s.pop();
    }

    return 0;
}