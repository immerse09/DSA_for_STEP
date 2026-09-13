#include<iostream>
#include<string>
using namespace std;

int studentPair(int n){

    // base case
    if(n==1 || n==2){
        return n;
    }

    // recurance relation
    return studentPair(n-1) + (n-1)*studentPair(n-2);
}

int main(){
    cout << studentPair(3);
    return 0;
}

// single
// studentPair(n-1)

// pair
// studentPair(n-2)

// for total ways = single + pair