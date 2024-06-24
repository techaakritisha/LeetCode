class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
       int n = nums.size();
        
       int flips = 0;
       
        vector<bool> check(n,false);
        
        int count = 0;
        
        for(int i=0; i<n; i++) {
            if(i >= k && check[i-k] == true) {
                count--;
            }
            
            if(count%2 == nums[i]) {
                if(i+k > n ) {
                    return -1;
                }
                count++;
                check[i] = true;
                flips++;
            }
        }
        return flips;
    }
};