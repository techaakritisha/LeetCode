class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> directions{{1,0},{0,-1},{-1,0},{0,1}};
    /*
    RECURSION + MEMOIZATION
    int M , N;
    int t[51][51][51];
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
        return t[i][j][k] = result%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        
        memset(t,-1,sizeof(t));
        return solve(startRow,startColumn,maxMove);
    }
    */
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       
        int dp[50][50][51];
        
        memset(dp,0,sizeof(dp));
        
        for(int k=1; k<=maxMove; k++){
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    for(auto &dir : directions) {
                         int x = i + dir[0];
                         int y = j + dir[1];
                        
                        if(x<0 || y<0 || x>=m || y>=n){
                            dp[i][j][k] = (dp[i][j][k]+1)%mod;
                        }
                        else{
                            dp[i][j][k] = (dp[i][j][k] + dp[x][y][k-1])%mod;
                        }
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove] ;
    }
};