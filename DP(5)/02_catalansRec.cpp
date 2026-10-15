#include<iostream>
using namespace std;

// recursion
int catRec(int n){
    if(n==0 || n==1){
        return 1;
    }

     int ans=0;
    for(int i=0; i<n; i++){
        ans += catRec(i) * catRec(n-i-1);
    }
    return ans;
}

// memoization
int catMem(int n, vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

     int ans=0;

    for(int i=0; i<n; i++){
        ans += catMem(i, dp) * catMem(n-i-1, dp);
    }
    return dp[n] = ans;
}


// tabulation
int catTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){//ith catalan
        for(int j=0; j<=n; j++){ //0 to i-1
            // dp[i] += cj * ci-j-1
            dp[i] += dp[j] * dp[i-j-1]; 
        }
    }
    return dp[n];
}

int main(){
    int n = 5;
    // vector<int> dp(n+1, -1);

    for(int i=0; i<=n; i++){
        cout << catTab(i) << " ";
    }
    cout << endl;

    // cout << catRec(n) << endl;
    return 0;
}
