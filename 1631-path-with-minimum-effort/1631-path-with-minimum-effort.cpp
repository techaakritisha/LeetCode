class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        int result[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result[i][j] = INT_MAX;
            }
        }
        // vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        
        priority_queue<p,vector<p>,greater<p>> pq;    
        
        pq.push({0,{0,0}});
        result[0][0] = 0;
        
        auto isSafe = [&](int x, int y){
            return (x>=0 && x<m && y>=0 && y<n) ;
        };
        
        
        while(!pq.empty()){
            int diff = pq.top().first;
            pair<int,int> p = pq.top().second;
            
            int x = p.first;
            int y = p.second;
            
            pq.pop();
            
            for(auto &dir : directions) {
               int new_x = x + dir[0];
               int new_y = y + dir[1];
               
               if(isSafe(new_x,new_y)){
                  int absdiff = abs(heights[x][y] - heights[new_x][new_y]);
                  int maxdiff = max(diff,absdiff);
                   
                  if(result[new_x][new_y] > maxdiff) {
                      result[new_x][new_y] = maxdiff;
                      
                      pq.push({maxdiff,{new_x,new_y}});
                      
                  }
               }
            } 
        }
        
        return result[m-1][n-1];
    }
};