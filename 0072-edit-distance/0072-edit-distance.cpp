class Solution {
public:
    /*
    int m , n ;
    int t[501][501];
    int solve(string &s1,string &s2 ,int i , int j) {
        if(i == m) {
            return n-j;
        }
        if(j == n){
            return m-i;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        if(s1[i] == s2[j]) {
            return  t[i][j] = solve(s1,s2,i+1,j+1);
        }
        
        int insert = 1 + solve(s1,s2,i,j+1);
        int deletechar = 1 + solve(s1,s2,i+1,j);
        int replace = 1 + solve(s1,s2,i+1,j+1);
        
        
        return t[i][j] = min({insert,deletechar,replace});
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        
        memset(t,-1,sizeof(t));
        return solve(word1,word2,0,0);
        
        
        */
    
        int minDistance(string word1, string word2) {
            
            int m = word1.length();
            int n = word2.length();
            vector<vector<int>> t(m+1,vector<int>(n+1,-1));
                
            for(int i=0; i<=m; i++) {
                for(int j=0; j<=n; j++) {
                    if(i==0 || j==0) {
                        t[i][j] = i + j;
                    }
                    else if(word1[i-1] == word2[j-1]){
                        t[i][j] = t[i-1][j-1];
                    }
                    else{
                        t[i][j] = 1 + min({t[i-1][j],t[i][j-1],t[i-1][j-1]});
                    } 
                }
            }
    
        return t[m][n];
    }
};