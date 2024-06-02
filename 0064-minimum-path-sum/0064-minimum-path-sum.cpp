class Solution {
public: 
   /*
    Top Down Approach
    int m, n ;
    int t[201][201];
    int solve(vector<vector<int>>& grid,int i ,int j) {
        
        if(i== m-1 && j == n-1) 
             return grid[i][j];
        
        if(t[i][j] != -1) 
          return t[i][j];

        if(i == m-1) 
          return t[i][j] = grid[i][j] + solve(grid,i,j+1);

        if(j == n-1) 
          return t[i][j] = grid[i][j] + solve(grid,i+1,j);
        
        else
          return t[i][j] = grid[i][j] + min(solve(grid,i+1,j),solve(grid,i,j+1));
        
        int ans = *min_element(grid[0].begin(),grid[0].end());

        return t[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

         memset(t,-1,sizeof(t));
         return solve(grid,0,0);
    }
    */
     
     //Bottom Up Approach
    /*
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m,vector<int>(n));

        t[0][0] = grid[0][0];

        for(int i=1; i<n; i++) {
           t[0][i] = grid[0][i] + t[0][i-1];
        }

        for(int j=1; j<m; j++) {
            t[j][0] = grid[j][0] + t[j-1][0];
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                t[i][j] = grid[i][j] + min(t[i-1][j],t[i][j-1]);
            }
        }
       return t[m-1][n-1];
        */
        
        int m , n;
        int t[201][201];
        int solve(vector<vector<int>> &grid , int i, int j) {
            if(i==m-1 && j==n-1)
                 return grid[i][j];
            
            if(t[i][j] != -1)
                return t[i][j];
            
            if(i == m-1){
               return t[i][j] = grid[i][j]+solve(grid,i,j+1);
            }
            
            if(j == n-1) {
                return t[i][j] = grid[i][j] + solve(grid,i+1,j);
            }
            else
               return t[i][j] = grid[i][j] + min(solve(grid,i+1,j),solve(grid,i,j+1));
            
            
            int ans = *min_element(grid[0].begin(),grid[0].end());
            
            return t[i][j] = ans;
         
        }
        int minPathSum(vector<vector<int>>& grid) {
            
            m = grid.size();
            n = grid[0].size();
            
            memset(t,-1,sizeof(t));
            return solve(grid,0,0);
    }
};