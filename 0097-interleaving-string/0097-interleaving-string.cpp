class Solution {
public:
    int t[102][102];
    bool solve(string &s1,string &s2,string &s3, int n, int m , int k) {
         if(k<0){
            return true;
        }
        
        if(t[n+1][m+1] != -1)
             return t[n+1][m+1];
        
        bool a1 = false,a2=false;
        
        if(n>=0 && s1[n]==s3[k]){
            a1 = solve(s1,s2,s3,n-1,m,k-1);
        }

        if(m>=0 && s2[m]==s3[k]){
            a2 = solve(s1,s2,s3,n,m-1,k-1);
        }

        return t[n+1][m+1] = a1||a2;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        
        if(k != n+m)
             return false;
        
        memset(t,-1,sizeof(t));
        
       return solve(s1,s2,s3,n-1,m-1,k-1);
    }
};