#include<iostream>
using namespace std;

void print(int n){
    if(n==0){ // base case
        return;
    }

    cout << n << " "; // kaam
    print(n-1); // faith
}

int main(){
    print(10);
    return 0;
}



// For increasing order 
void print(int n){
    if(n==0){ // base case
        return;
    }

    // pahle chhoti wali print hogi then bari wali
    print(n-1); // faith
    cout << n << " "; // kaam
}

int main(){
    print(10);
    return 0;
}



