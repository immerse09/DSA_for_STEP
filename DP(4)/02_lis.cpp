#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int lis(vector<int> arr){ //O(n^2)
    // all unique value store in the set
    unordered_set<int> s(arr.begin(), arr.end()); //O(n)

    // also can by loop 
    // for(int el : arr){
    //     s.insert(el);
    // }

     // for copy
    // for(int el : s){
    //     arr2.push_back(el);
    // }

    // shortcut to copy those unique in arr2
    vector<int> arr2(s.begin(), s.end()); //
    sort(arr2.begin(), arr2.end()); //ascending sorted order - O(nlogn)

    // LCS => LIS
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++){ //O(n*n)
        for(int j=1; j<m+1; j++){
            if(arr[i-1] == arr2[j-1]){
                dp[i][j] =  1 + dp[i-1][j-1];
            } else { //NO
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] =  max(ans1, ans2);
            }
        }
    }
    return dp[n][m];

}

int main(){
    vector<int> arr = {50, 3, 10, 7, 40, 80};

    cout << lis(arr) << endl;

    return 0;
}