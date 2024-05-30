class Solution {
public:
    string convert(string s, int numRows) { 
      vector<string> ans(numRows); 
      if(numRows == 1){
          return s;
      }
      bool flag = false;
      int i = 0;       
      
      for(auto c : s){
          ans[i] += c;
          if(i == 0 || i == numRows-1){
              flag = !flag;
          }
          if(flag){
              i += 1;
          }
          else{
              i -= 1;
          }
      }
      string zig = "";

      for(auto a : ans){
          zig += a;
      }
      return zig;
    }
};