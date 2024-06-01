class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        
        for(int i=0; i<s.length()-1; i++) {
           int v1 = int(s[i]);
           int v2 = int(s[i+1]);
           
            sum += abs(v1 - v2);
        }
        return sum ;
    }
};