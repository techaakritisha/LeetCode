class Solution {
public:
    int n;
    int t[51];
    unordered_set<string> st ;
    int solve(int idx,string &s) {
        if(idx >= n) 
             return 0;
        
        if(t[idx] != -1)
            return t[idx];
        
        int extra = n;
        string curr = "";
        
        for(int i=idx; i<n; i++) {
            curr.push_back(s[i]);
            
            int currextra = (st.find(curr) == st.end()) ? curr.length() : 0;
            int remain = solve(i+1,s);
            int total = currextra + remain;
            
            extra = min(extra,total);
        }
        return t[idx] = extra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.length();
        
        for(int i=0; i<dictionary.size(); i++) {
            st.insert(dictionary[i]);
        }
        
        memset(t,-1,sizeof(t));
        return solve(0,s);
    }
};