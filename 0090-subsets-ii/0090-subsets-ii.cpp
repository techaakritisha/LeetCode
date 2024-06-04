class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
        int n = nums.size();
        
        if(n == 1) {
            vector<vector<int>> res;
            res.push_back({});
            res.push_back({nums[0]});
            return res;
        }
         
         set<vector<int>> result;
        
         for(int i=0; i<(1<<n); i++) {
            vector<int> temp;
            for(int j=0; j<n; j++) {
                if(i&(1<<j)){
                  temp.push_back(nums[j]);   
                }
                sort(temp.begin(),temp.end());
                result.insert(temp);
            }
             sort(temp.begin(),temp.end());
            result.insert(temp);
        }
        
        vector<vector<int>> ans(result.begin(),result.end());
       
        return ans ;
    }
};