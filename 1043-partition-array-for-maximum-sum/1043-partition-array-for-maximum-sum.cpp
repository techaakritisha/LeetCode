class Solution {
public:
    
    /*
    int n;
    int t[501];
    int solve(vector<int>& arr, int idx, int k) {
        if(idx >= n) {
            return 0;
        }
        
        if(t[idx] != -1) {
            return t[idx];
        }
        
        int result = 0;
        int curr_max = -1;
        for(int i = idx; i < n && i-idx+1 <= k; i++) {
            curr_max = max(curr_max, arr[i]);
            
            result = max(result, curr_max*(i-idx+1) + solve(arr, i+1, k));
        }
        
        return t[idx] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 0, k);
    }
    
    */
     
    /*
     int n ;
     int dp[505];
     int solve(int i,int k , vector<int> &nums) {
         if(i >= n)
              return 0;
         
         if(dp[i] != -1)
             return dp[i];
         
         int result = 0;
         int curr = -1;
         for(int j=i; j<n && j-i+1 <= k ; j++) {
             curr = max(curr,nums[j]);
             
             result = max(result,(j-i+1)*curr + solve(j+1,k,nums));
         }
         return dp[i] = result;
     }
     int maxSumAfterPartitioning(vector<int>& arr, int k){
       
      n = arr.size();  
      
      memset(dp,-1,sizeof(dp));
      return solve(0,k,arr);
       */
      int maxSumAfterPartitioning(vector<int>& arr, int k){
        int n = arr.size();
        
          vector<int> dp(n+1,0);
          
          for(int i=1; i<=n; i++){
              int currmaxi = -1;
              for(int j=1; j<=k && (i-j)>=0; j++) {
                currmaxi = max(currmaxi,arr[i-j]);
                dp[i] = max(dp[i],(j*currmaxi)+dp[i-j]);
              }
        }
          return dp[n];
    }  
};