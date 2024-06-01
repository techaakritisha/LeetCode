class Solution {
public:
    vector<vector<int>> generate(int n) {
      vector<vector<int>> dp(n);
        
        for(int i=0; i<n; i++) {
            dp[i] = vector<int> (i+1,1);
            for(int j=1; j<i; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        return dp;
    }
};