#include<iostream>
#include<queue>
using namespace std;

void firstNonRepeating(string str){ //O(n) O(n) 
    queue<char> Q;
    int freq[26] = {0};

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        Q.push(ch);
        freq[ch-'a']++; // ch-'a' i.e index of that char

        while(!Q.empty() && freq[Q.front()-'a'] > 1){
            Q.pop();
        }

        if(Q.empty()){
            cout << "-1\n";
        } else {
            cout << Q.front() << "\n";
        }
    }
}

int main(){
    string str = "aabccxb";
    firstNonRepeating(str);
    return 0;
}