class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v(begin(heights),end(heights));
        
        sort(begin(v),end(v));
        int count = 0;
        
        for(int i=0; i<v.size(); i++){
            if(heights[i] != v[i])
                count++;
        }
        return count;
    }
};