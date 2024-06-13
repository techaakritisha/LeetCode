class Solution {
public:
    int n;
    int t[501][501];
    int solve(int i,int remain , vector<int> &cost,vector<int> &time) {
         
        if(remain <= 0)
            return 0;
        
        if(i >= n)
            return 1e9;
        
        if(t[i][remain] != -1)
            return t[i][remain];
        
        int take = cost[i] + solve(i+1,remain-1-time[i],cost,time);
        int leave =  solve(i+1,remain,cost,time);
            
      
       return t[i][remain] =  min(take,leave);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
       n = cost.size();
       
        memset(t,-1,sizeof(t));
       return solve(0,n,cost,time);
    }
};