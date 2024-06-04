class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n= nums.size();
       int cnt = 0;
       for(int i=0;i<n;i++){
           if(nums[i]==target){
               cnt++;
           }
           else{
               continue;
           }
       }
       if(cnt>0){
           return true;
       }
       else{

           return false;
       }
    }
};