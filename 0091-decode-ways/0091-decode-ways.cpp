class Solution {
public:
    int n ;
    int t[101];
    int solve(int i,string &s) {
        if(i == n) 
            return 1;
        
        if(s[i] == '0')
          return 0;
        
        if(t[i] != -1)
             return t[i];
        
        int op1 = solve(i+1,s);
        
        if(i+1 < n) {
            if(s[i]=='1' || s[i] == '2' && s[i+1] <= '6') 
                op1 += solve(i+2,s);
        }
        
        return t[i] = op1;
    }
    int numDecodings(string s) {
        n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,s);
    }
};