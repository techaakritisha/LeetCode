class Solution {
public:
    vector<vector<int>> direc{{1,1},{1,0},{-1,0},{-1,-1},{0,-1},{0,1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        auto isSafe = [&](int x,int y){
            return x>=0 && x<m && y>=0 && y<n;
        };
        
        if(m == 0 || n == 0 || grid[0][0] != 0)
             return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--) {
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                if(x == m-1 && y == n-1){
                    return level+1;
                }
                
                for(auto &dir : direc){
                    int newx = x + dir[0];
                    int newy = y + dir[1];
                    
                    if(isSafe(newx,newy) && grid[newx][newy] == 0){
                        q.push({newx,newy});
                        grid[newx][newy] = 1;
                    }
                }  
            }
            level++;
         }
        return -1;
    }
};