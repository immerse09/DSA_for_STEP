// google , amazon
#include<iostream>
using namespace std;

// int tp(int n){
//     // base case 
//     if(n==0 || n==1) return 1;

//     // vertical
//    int ans1 = tp(n-1); // 2*n-1

//    // horizontal
//    int ans2 = tp(n-2); // 2*n-2

//    return  ans1+ans2;
// }

// int main(){
//     int n=6;
//     cout<<tp(n)<<endl;
//     return 0;
// }


// also
int tp(int n){
    if(n==0 || n==1)
    return 1;
    return tp(n-1) + tp(n-2);
}
int main(){
    cout << tp(10) << endl;
}