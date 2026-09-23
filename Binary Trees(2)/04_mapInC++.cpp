#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> m;

    m[101] = "rahul";
    m[110] = "neha";
    m[131] = "rahul";

    cout <<m[101] << endl; // rahul
    cout << m.count(131); //1

    // print 
    for(auto it : m){
        cout << "key = " << it.first << "," << "value = " << it.second << endl;
    }
    return 0;
}
