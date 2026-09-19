#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBottom(stack<int> &s, int val){ // O(n)
    // base case
    if(s.empty()){
        s.push(val);
    }

    int temp = s.top(); // store top val
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

// func for reverse string question
string reverseString(string str){
    string ans;
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

// for reverse stack 
void reverse(stack<int> s){ //O(n)
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> &s){ // pass by refernse
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
   return 0;
}