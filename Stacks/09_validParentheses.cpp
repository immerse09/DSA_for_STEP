#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string str){ // O(n)
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        } else { // closing
            if(s.empty()){
                return false;
            }

            // match
            int top = s.top();
            if((top == '(' && ch == ')') ||
             (top == '[' && top == ']') ||
             (top == '{' && top == '}')){
                s.pop();
             } else {
                return false;
             }
        }
    }
    // also return s.empty();
    if(s.empty()){
        return true;
    } else {
        return false;
    }
}


int main(){
    string str1 = "([}])"; // invalid : false
    string str2 = "([{}])"; //valid : false

    cout << isValid(str1) << endl;
    cout << isValid(str2) << endl;
    return 0;
}