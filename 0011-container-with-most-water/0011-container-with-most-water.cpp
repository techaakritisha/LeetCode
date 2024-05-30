class Solution {
public:
    const int MOD = 1e9+7;
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxarea = 0;

        while(l < r) {
            int curr = min(height[l],height[r]) * (r-l);
            maxarea = max(maxarea,curr);

            if(height[l] < height[r]){
               l++;
            }
            else {
                r--;
            }
        }

        return maxarea;
    }
};