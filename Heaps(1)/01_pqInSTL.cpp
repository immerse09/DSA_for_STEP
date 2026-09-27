#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    // priority_queue<int> pq; //descending
    //  priority_queue<int, vector<int>, greater<int>> pq; // ascending
    priority_queue<string, vector<string>, greater<string>> pq;

    // pq.push(5);
    // pq.push(10);
    // pq.push(9);
    // pq.push(7);
    // pq.push(3);
    // pq.push(2);

    pq.push("helloworld");
    pq.push("apnacollege");
    pq.push("c++");
    pq.push("alpha");
    pq.push("custom");
    pq.push("zone");

    // cout << pq.top() << endl; // 10

    while(!pq.empty()){
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }

    // top : 10
    // top : 9
    // top : 7
    // top : 5
    // top : 3
    // top : 2

    // if we want result in reverse order then we use,
    // pass container and pass custom container

    // priority_queue<int, vector<int>, greater<int>> pq;
// top : 2
// top : 3
// top : 5
// top : 7
// top : 9
// top : 10
    return 0;
}