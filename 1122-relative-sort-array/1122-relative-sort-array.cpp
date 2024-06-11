class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int maxi = *max_element(begin(arr1),end(arr1));
        
        vector<int> count(maxi+1);
        
        for(int ele : arr1) {
            count[ele]++;
        }
        
        vector<int> ans;
        
        for(int ele :arr2) {
            while(count[ele] > 0) {
                ans.push_back(ele);
                count[ele]--;
            }
        }
        
        
        for(int i=0; i<=maxi; i++) {
            while(count[i] > 0) {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};