class Solution {
public:
    vector<string> result;
    int n;
    bool isValid(string s) {
        if(s[0] == '0')
            return false;
        int val = stoi(s);
        
        return val <= 255 ;
    }
    void solve(string &s ,int idx,int parts,string curr) {
        if(parts == 4 && idx == n){
            curr.pop_back();
            result.push_back(curr);
            return ;
        }
        
        if(idx+1 <= n ) {
            solve(s,idx+1 , parts+1 , curr + s.substr(idx,1) + ".");
        }
        if(idx+2 <= n && isValid(s.substr(idx,2))) {
            solve(s,idx+2,parts+1,curr + s.substr(idx,2) + ".");
        }
        if(idx+3 <= n && isValid(s.substr(idx,3))) {
            solve(s,idx+3,parts+1,curr + s.substr(idx,3) + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;  
        n = s.length();
        if(s.length()<4 || s.length() > 12)
            return res;
        
        string curr = "";
        int parts = 0; 
       
       solve(s,0,parts,curr);
        
        return result;
    }
};