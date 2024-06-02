class Solution {
public:
  void reverseeString(vector<char> &str , int s , int e ){
    
   if(s > e){
    return ; 
   }
  
   swap(str[s],str[e]);
   s++;
   e--;

   reverseeString(str,s,e);
   
  }
    void reverseString(vector<char>& s) {
         
         reverseeString(s,0,s.size()-1);
    }
};