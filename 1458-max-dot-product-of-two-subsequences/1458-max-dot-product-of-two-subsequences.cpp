class Solution {
public:
    int n , m;
    int t[501][501];
    int solve(int i,int j,vector<int> &num1 , vector<int> &num2) {
        
        if(i==n || j==m){
            return -1e9;
        }  
      
         if(t[i][j] != -1)
             return t[i][j];
        
        int val = num1[i] * num2[j];
        int takeij = num1[i]*num2[j]+solve(i+1,j+1,num1,num2);
        int takei = solve(i+1,j,num1,num2);
        int takej = solve(i,j+1,num1,num2);
        
        return t[i][j] = max({val,takeij,takei,takej});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
    }
};