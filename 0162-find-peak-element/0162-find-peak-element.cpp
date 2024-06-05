class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
          return 0;
        
        if(n == 2) {
            return nums[1] > nums[0] ? 1 : 0;
        }
        
        for(int i=1; i<n-1; i++) {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
        
        int maxi = *max_element(begin(nums),end(nums));
        int ind = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == maxi)
               ind = i;
        }
        return ind;
    }
};