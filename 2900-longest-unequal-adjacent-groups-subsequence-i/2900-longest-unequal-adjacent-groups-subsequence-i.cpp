class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        
        res.push_back(words[0]);
        
        int n = words.size();
        
        for(int i=1; i<n; i++) {
            if(groups[i-1] != groups[i]){
                res.push_back(words[i]);
           }
        }
        
        return res;
    }
};