class Solution {
public:
    int n ;
    int t[101][101];
    int solve(int l , int r, string &s) {
       if(l == r) 
           return 1;
        
        if(l > r)
            return 0;
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int i = l+1;
        
        while(l <= r && s[i] == s[l]){
            i++;
        }
        
        if(i == r+1)
            return 1;
        
        int basic = 1 + solve(i,r,s);
        
        int lalatch = INT_MAX;
        
        for(int j=i; j<n; j++){
            if(s[j] == s[l]){
                int ans = solve(i,j-1,s) + solve(j,r,s);
                lalatch = min(lalatch,ans);
            }
        }
        return t[l][r] = min(lalatch,basic);
    }
    int strangePrinter(string s) {
        
        n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};