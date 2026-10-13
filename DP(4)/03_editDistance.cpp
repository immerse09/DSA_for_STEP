class Solution {
public:
    int minDistance(string word1, string word2) { //O(n*m)
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int j=0; j<m+1; j++){ //0th row initialize - insertion
            dp[0][j] = j;
        }

        for(int i=0; i<n+1; i++){ //0th col initialize - deletion
            dp[i][0] = i;
        }

        // bottom-up fill up
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                } else { //NO
                    int ans1 = dp[i][j-1];
                    int ans2 = dp[i-1][j];
                    int ans3 = dp[i-1][j-1];
                    dp[i][j] = 1 + min(min(ans1, ans2), ans3);
                }
            }
        }
        return dp[n][m];
    }
};