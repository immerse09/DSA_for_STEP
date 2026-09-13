#include<iostream>
using namespace std;

void bs(int n, int lastPlace, string ans){
    // base case
    if(n==0){
        cout << ans << endl;
        return;
    }

    // rec. func
    if(lastPlace != 1){
     bs(n-1, 0, ans+'0');
     bs(n-1, 1, ans+'1');
    }
     else{
        bs(n-1, 0, ans+'0');
     }
}

int main(){
    string ans = "";
    bs(3, 0, ans);
    return 0;
}

// without lastPlace 

void bs(int n, string ans){
    // base case
    if(n==0){
        cout << ans << endl;
        return;
    }

    // rec. func
    if(ans[ans.size()-1] != 1){ // dont try check == 0 
     bs(n-1, 0, ans+'0');
     bs(n-1, 1, ans+'1');
    }
     else{
        bs(n-1, 0, ans+'0');
     }
}

// note: we can't check == 0 bec. in ans="" it doesn't aknowledge cleary

int main(){
    string ans = "";
    bs(3, ans);
    return 0;
}




// void printBinaryString(int n, int lastPlace, string ans){
//     if(n==0){
//         cout << ans << endl;
//         return;
//     }
//     if(lastPlace != '1'){
//         printBinaryString(n-1, 0, ans+'0');
//         printBinaryString(n-1, 1, ans+'1');
//     } else {
//         printBinaryString(n-1, 0, ans+'0');
//     }
// }

// int main(){
//     string ans = "";
//      printBinaryString(4, 0, ans);
//     return 0;
// }