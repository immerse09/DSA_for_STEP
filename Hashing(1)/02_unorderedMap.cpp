#include<iostream>
#include<unordered_map>
#include<map>
using namespace std; 

int main(){
    // unordered_map<string, int> m;
    map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;
    m["Nepal"] = 200;

    // cout << m["China"] << endl; // 150

    for(pair<string, int> country : m){
        cout << country.first << "," << country.second << endl;
    }


    if(m.count("Canada")){
        cout << "Canada exists\n";
    } else {
        cout << "Canada doesn't exists\n";
    }

    // erase
    m.erase("Nepal");

// Note: unordered_map and map both work equally only diff of map give result in 
// specific ordered

    return 0;
}
