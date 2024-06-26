class Solution {
public:
    int mod = 1e9+7;
    int M , N;
    int t[51][51][51];
    vector<vector<int>> directions{{1,0},{0,-1},{-1,0},{0,1}};
    int solve(int i ,int j,int k){
        if(i<0 || i>=M || j<0 || j>=N)
          return 1;
    
        if(k <= 0)
            return 0;
        
        if(t[i][j][k] != -1)
            return t[i][j][k] ;
        
        int result = 0;
        
        for(auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            result = (result + solve(new_i , new_j , k-1))%mod;
        }
        return t[i][j][k] = result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        
        memset(t,-1,sizeof(t));
        return solve(startRow,startColumn,maxMove);
    }
};