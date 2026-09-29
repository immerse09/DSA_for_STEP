#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
using namespace std; 

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(7);
    // s.insert(1); // Note: duplicate doesn't increase size
    // s.insert(1);
    // s.insert(1);

    cout << s.size() << endl;

    if(s.find(3) != s.end()){
        cout << "3 exists " << endl;
    } else {
        cout << "3 not exists " << endl;
    }

    for(auto el : s){
        cout << el << " ";
    }
    return 0;

}