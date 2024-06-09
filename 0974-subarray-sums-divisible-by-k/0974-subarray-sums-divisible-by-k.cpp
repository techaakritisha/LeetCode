class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>m;
        m.insert({0,1});
        int sum=0,rem=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
            {
                rem+=k;
            }

            if(m.find(rem)!=m.end()){
                ans+=m.at(rem);
              m[rem]++;
            }
            else
            {
                m.insert({rem,1});
            }
         
        }
        return ans;
    }
};