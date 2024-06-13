class Solution {
public:
    /*
    double t[101][101];
    double solve(int i , int j,int P){
        if(i<0 || j<0 || i<j)
             return 0.0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(i == 0 && j == 0)
             return  P;
        
        double left = (solve(i-1,j,P)-1)/2.0;
        double right = (solve(i-1,j-1,P)-1)/2.0;
        
        if(left < 0){
            left = 0.0;
        }
        if(right < 0){
            right = 0.0;
        }
        
        return t[i][j] = left+right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        
        
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++) {
                t[i][j] = -1;
            }
        }
        

        return min(1.0 ,solve(query_row,query_glass,poured));
    }
    
    */
    
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101,vector<double>(101,0.0));
        
        dp[0][0] = (double)poured;
        
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++) {
                
                double extra = (dp[i][j]-1.0)/2.0;
                
                if(extra>0){
                    dp[i+1][j] += extra;
                    dp[i+1][j+1] += extra;
                }
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};