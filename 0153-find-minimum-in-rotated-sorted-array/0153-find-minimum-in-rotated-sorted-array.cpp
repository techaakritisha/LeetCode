class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        
        if(n == 2) {
            return min(nums[1],nums[0]);
        }
        
        for(int i=1; i<n-1; i++) {
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                return nums[i];
            }
        }
        int ans = *min_element(begin(nums),end(nums));
        return  ans;
    }
};