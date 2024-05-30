class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
    //     unordered_map<int ,int> mp;
    //     vector<int> v;
    //     int n = nums.size() ; 
        
    //     for(int i=0; i<n; i++){
    //         mp[nums[i]] = i;
    //     }
       
    //    for(int i=0; i<n; i++){
    //        int com = target-nums[i];

    //        if(mp.count(com) && mp[com] != i){
    //            return {i,mp[com]};
    //        }
    //     }
    //     return {};
       vector<int> v;
       int n = arr.size();

       for(int i=0; i<n ;i++){
           int sum = 0;
           for(int j=i+1; j<n; j++){
              sum = arr[i] + arr[j];
              if(sum == target){
                  v.push_back(i);
                  v.push_back(j);
              }
           }
       }
       return v;
    }
};