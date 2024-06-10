class Solution {
public:
    int n;
    int t[301][5001];
    int solve(int i , int amount , vector<int> &nums) {
        if(amount == 0)
             return  1;
        
        if(i == n)
             return 0;
        
        if(t[i][amount] != -1)
             return t[i][amount];
        
        if(nums[i] > amount) {
            return t[i][amount] = solve(i+1,amount,nums);
        }
        
        int take = solve(i,amount-nums[i],nums);
        int skip = solve(i+1,amount,nums);
        
        
        return t[i][amount] = take+skip ;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};