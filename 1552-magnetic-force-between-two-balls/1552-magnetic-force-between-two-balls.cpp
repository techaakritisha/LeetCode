class Solution {
public:
    bool isPossible(int force , vector<int> &position , int m) {
        int prev = position[0];
        int count = 1;
        
        for(int i=1; i<position.size(); i++) {
            int curr = position[i];
            
            if(curr-prev >= force) {
                count++;
                prev = curr;
            }
            
            if(count == m)
                break;
        }
        
        return count == m;
    }
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        
        sort(begin(position),end(position));
        int mini = 1;
        int maxi = position[n-1]-position[0];
        int ans = 0;
        
        while(mini <= maxi) {
            int mid = mini + (maxi-mini)/2;
            
            if(isPossible(mid,position,m)){
                ans = mid;
                mini = mid + 1;
            }
            else{
                maxi = mid-1;
            }
        }
        return ans;
    }
};