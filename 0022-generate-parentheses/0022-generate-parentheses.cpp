class Solution {
public:
    bool isValid(string &s) {
        int count = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }
            
            if(count<0) {
                return false;
            }
        }
        
        return count==0?true:false;
    }
    
    vector<string> res;
    void solve(string &curr , int n) {
      if(curr.length() == 2*n) {
          if(isValid(curr)){
              res.push_back(curr);
          }
          return;
      }   
        
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
       string curr = "";
        
        solve(curr,n);
        return res;
    }
};


