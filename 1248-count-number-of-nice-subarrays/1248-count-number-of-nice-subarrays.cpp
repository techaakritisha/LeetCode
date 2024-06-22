class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       
        int n = nums.size();
        int curr = 0;
        mp[0] = 1;
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i]%2 != 0) 
                curr += 1;
            
            
            if(mp.count(curr-k)){
                count += mp[curr-k];
            }
            
            mp[curr]++;
        }
       return count;
    }
};