class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v;
        int st = 0 , end = nums.size()-1;

        while(st < end) {
            int total = nums[st] + nums[end];

            if(total == target){
                return {st+1,end+1};
            }
            if(total > target){
                end--;
            }
            else{
                st++;
            }
        }
        return {-1,-1};
    }
};