class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        
        int n = arr.size();
        int res = 0;
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++) {
           int prev = arr[i] - d;
            int prevtocurr_len = mp[prev];
            mp[arr[i]] = prevtocurr_len + 1;
            
            res = max(res,mp[arr[i]]);
        }
        
        return res;
    }
};