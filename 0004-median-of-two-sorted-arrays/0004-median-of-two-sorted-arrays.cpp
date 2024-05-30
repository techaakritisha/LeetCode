class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   /*  
     vector<int> v;

     for(auto num:nums1)
        v.push_back(num);
     
     for(auto num:nums2)
       v.push_back(num);

       sort(v.begin(),v.end());

       int n = v.size();

       return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;  
    */

      vector<int> v;

      for(auto it:nums1){
          v.push_back(it);
      }
      for(auto it:nums2){
          v.push_back(it);
      }
      sort(v.begin(),v.end());
      
      double ans = 0 ;

      if(v.size()%2 != 0){
         ans = v[v.size()/2];
      }
      else{
         ans = (v[v.size()/2] + v[v.size()/2-1])/2.0;
      }
      return ans ;
    } 
};