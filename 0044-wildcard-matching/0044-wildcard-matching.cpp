class Solution {
public:
    /*
    int n , m ;
    int dp[2001][2001];
     bool solve(int i,int j,string &s, string &p,vector<vector<int>> &dp) {
        
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0 ){
            if(p[j]=='*' && j==0)
                return true;
            for(int x=0;x<=j;x++){
                if(p[x]!='*')
                    return false;
            }
             return true;
        }   
        if(j<0 && i>=0 )
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*')
            return dp[i][j]=solve(i,j-1,s,p,dp) ||solve(i-1,j,s,p,dp);
        return dp[i][j] =false;
        
    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p,dp);
        
        */
     bool isMatch(string s, string p){
        int n = s.size();
        int m = p.size();

        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;

        // base case
        for(int j = 1;j<=m;j++){
            if(p[j-1]=='*'){
                dp[0][j]=true;
            }
            else{
                break;
            }
        }
         
          for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1] ;
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
                
            }
        }

        return dp[n][m];
    }
};