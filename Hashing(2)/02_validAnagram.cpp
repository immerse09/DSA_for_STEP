#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

bool validAnagram(string s, string t){
    if(s.size() != t.size()){
        return false;
    }
    // for s <char, freq>
    unordered_map<char, int> m;
    for(int i=0; i<s.size(); i++){
        if(m.count(s[i])) {
            m[s[i]]++;
        } else {
            m[s[i]] = 1;
        }
    }

    // 2nd to lool for t's chars in freq
    for(int i=0; i<t.size(); i++){
        if(m.count(t[i])) {
            m[t[i]]--;
            if(m[t[i]] == 0){
                m.erase(t[i]);
            }
        } else {
            return false;
        }
    }

    return m.size() == 0;
}

int main(){
    string s = "race";
    string t = "care";

    cout << validAnagram(s, t) << endl;
    

    return 0;
}
