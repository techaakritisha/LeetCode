class Solution {
public:
    int t[1001];
    int solve(int i , vector<int> &cost) {
        if(i >= cost.size()){
            return 0;
        }
        
        if(t[i] != -1) 
             return t[i];
        
        int op1 = solve(i+1,cost) + cost[i];
        int op2 = solve(i+2,cost) + cost[i];
        
        return t[i] = min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
         memset(t,-1,sizeof(t));
         return min(solve(0,cost),solve(1,cost));
    }
};