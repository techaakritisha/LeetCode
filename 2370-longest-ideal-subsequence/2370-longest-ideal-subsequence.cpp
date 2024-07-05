class Solution {
public:
    /*
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        int len = 1;
        int prev = s[0] - 'a';
        
        for(int i=1; i<n; i++){
            int curr = s[i] - 'a';
            
            if(abs(curr-prev) <= k) {
                len = len+1;
                
                prev =  curr;
            }
        }
        return len==1 ? 2 : len;
        
        */
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        int result = 0;
        
        vector<int> t(26,0);
        
        for(int i=0; i<n; i++) {
            int curr = s[i] - 'a';
            
            int left = max(0,curr-k);
            int right = min(25,curr+k);
            
            int longest = 0;
            for(int j=left; j<=right; j++) {
                longest = max(longest,t[j]);
            }
            t[curr] = max(longest+1,t[curr]);
            
            result = max(result,t[curr]);
        }
        
        return result;
    }
};