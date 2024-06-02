class Solution {
public:
    unordered_set<int> visit;
    bool canReach(vector<int>& arr, int start) {
        
         if(visit.count(start) || start<0 || start>arr.size())
             return false;
        
        if(arr[start] == 0)
             return true;
        
        visit.insert(start);
        
          return canReach(arr,start-arr[start]) || canReach(arr,start+arr[start]);
    }
};