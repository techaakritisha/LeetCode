class Solution {
public:
    typedef pair<int,int> p;
    int primAlgo(vector<vector<p>> &adj , int v) {
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        
        vector<bool> isMST(v,false);
        int sum = 0;
        
        while(!pq.empty()) {
            auto t = pq.top();
            int wt = t.first;
            int node = t.second;
            
            pq.pop();
            
            if(isMST[node] == true)
                continue;
            
            isMST[node] = true;
            sum += wt;
            
            for(auto &it : adj[node]){
                int neigh = it.first;
                int  w = it.second;
                
                if(isMST[neigh] == false){
                    pq.push({w,neigh});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int v = points.size();
        vector<vector<p>> adj(v);
        
        for(int i=0; i<v; i++) {
             for(int j=i+1; j<v; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                
                int d = abs(x1-x2)+abs(y1-y2);
                
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }        
        return primAlgo(adj,v);
    }
};