#include<iostream>
using namespace std;

void print(){
    cout << "Aman Nayak";
    print();
}

int main(){
    print();
    
}

// Note: infinite recursion cz missing of base case
//     op: segmentaion fault