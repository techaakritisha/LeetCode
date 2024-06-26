class Solution {
public:
   
    vector<vector<int>> direc{{1,1},{1,0},{-1,0},{-1,-1},{0,-1},{0,1},{1,-1},{-1,1}};
    /*
    USING BFS
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
    
    */
    typedef pair<int,pair<int,int>> p;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(n == 0 || m==0 || grid[0][0] != 0)
            return -1;
        
        auto isSafe = [&](int x,int y) {
            return (x>=0 && x<m && y>=0 && y<n);
        };
        
        
        //Min heap
        priority_queue<p,vector<p>,greater<p>> pq;
        //2D Result vector
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        
        pq.push({0,{0,0}});
        
        result[0][0] = 0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            
            pq.pop();
            
            for(auto dir:direc) {
                int newx = x+dir[0];
                int newy = y+dir[1];
                
                int dist = 1;
                
                if(isSafe(newx,newy) && grid[newx][newy] == 0 && d+dist < result[newx][newy]) {
                    pq.push({d+dist,{newx,newy}});
                    grid[newx][newy] = 1;
                    result[newx][newy] = d+dist;
                    
                }
                
            }
                
        }
        return result[m-1][n-1]==INT_MAX?-1 : result[m-1][n-1]+1;
    }
};