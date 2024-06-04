class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int odd = 0;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;

            if(mp[s[i]] %2 == 1) {
                odd++;
            }
            else{
                odd--;
            }
        }

        if(odd > 1) {
            return s.length()-odd+1;
        }
        else{
            return s.length();
        }
    }
};