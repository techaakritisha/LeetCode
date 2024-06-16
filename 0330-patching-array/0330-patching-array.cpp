class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int pitch = 0;
        int i = 0;
        long maxreach = 0;
        
        while(maxreach < n ) {
            if(i<nums.size() &&  nums[i] <= maxreach+1) {
                maxreach += nums[i];
                i++;
            }
            else{
                maxreach += (maxreach + 1);
                pitch++;
            }
        }
        return pitch;
    }
};