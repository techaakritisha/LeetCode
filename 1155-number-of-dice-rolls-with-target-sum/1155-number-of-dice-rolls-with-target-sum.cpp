class Solution {
public:
    
    /*
    int mod = 1e9+7;
    int t[31][1001];
    int solve(int n, int k , int target) {
        if(n == 0) 
            return target == 0;
        
        if(target < 0)
             return 0;
        
        if(t[n][target] != -1)
            return t[n][target];
        
        int ans = 0;
        
        for(int i=1; i<=k; i++){
            ans = (ans + solve(n-1,k,target-i))%mod;
        }
        return t[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        memset(t,-1,sizeof(t));
        return solve(n,k,target);
    }
    
    */
    
    
    // BOTTOM UP
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
               int ways = 0;
                for(int dice=1; dice<=k; dice++) {
                    
                    if(j >= dice)
                    ways = (ways + dp[i-1][j-dice])%mod;
                    
                }
                dp[i][j] = ways;
            }
        }
        return dp[n][target];
    }
};