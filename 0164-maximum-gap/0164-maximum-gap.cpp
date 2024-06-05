class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums),end(nums));
        
        if(n < 2)
            return 0;
        
        if(n == 2)
            return nums[1]-nums[0];
        
        int diff = INT_MIN;
        
        for(int i=1; i<n; i++){
          diff = max(diff , nums[i]-nums[i-1]);    
        }
        return diff;
    }
};