class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //  int count[256] = {0};
        //  int r = 0;
        //  int l = 0;
        //  int ans = 0;
        //  while(r<s.size()){
        //      count[s[r]]++;

        //      while(count[s[r]]>1){
        //          count[s[l]]--;
        //          l++;
        //      }
        //      ans = max(ans , r-l+1);
        //      r++;
        //  }
        //  return ans;
        /*
          int len = 0 ;
          int  maxlen = 0  , j = 0;

          map<char,int> mp;

          for(int i=0; i<s.length(); i++){
             mp[s[i]]++;
             len++;
             while(mp[s[i]] > 1){
                 mp[s[j++]]--;
                 len--;
             }
             maxlen = max(maxlen,len);
          }
          return maxlen;
          */

          int l = 0;
          int maxlen = 0;

          unordered_set<char> st;

          for(int i=0; i<s.length(); i++) {
            while(st.find(s[i]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            st.insert(s[i]);
            maxlen = max(maxlen,i-l+1);
          }
          return maxlen;
    }
};