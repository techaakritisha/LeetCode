class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++){
           mp[nums[i]]++;   
        }
        
        vector<pair<int,int>> p;
        
        for(auto a : mp){
            p.push_back(a);
        }
        
        sort(p.begin(),p.end(),[](pair<int,int> a, pair<int,int> b){
           return a.second>b.second; 
        });
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(p[i].first);
        }
        return ans;
    }
};