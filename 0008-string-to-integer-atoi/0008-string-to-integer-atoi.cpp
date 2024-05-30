class Solution {
public:
    int myAtoi(string s) {
    int i=0 , n=s.size();

    while(s[i]==' '){
        i++;
    }
    int pos = 0 , neg = 0;
    if(s[i]=='+'){
      pos++;
      i++;
     }
     if(s[i]=='-'){
         neg++;
         i++;
      }
      double ans = 0;
      while(i<n && s[i]>='0' && s[i] <= '9'){
          ans = ans*10 + (s[i]-'0');
           i++;
      }
      if(neg >0)
      ans = -ans;
      
      if(pos>0 && neg >0)
      return 0;

      if(ans>INT_MAX)
       ans = INT_MAX;

       if(ans<INT_MIN)
        ans = INT_MIN;

        return (int)ans;
    }
};