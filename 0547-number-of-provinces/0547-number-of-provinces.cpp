class Solution {
public:
    void BFS(unordered_map<int,vector<int>> &adj, int u , vector<bool> &visited) {
        queue<int> q;
        q.push(u);
        
        visited[u] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(int &v : adj[front]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        unordered_map<int,vector<int>> adj;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n,false);
        int count = 0;
        
        for(int i=0; i<n; i++) {
            for(int &v : adj[i]){
                if(!visited[v]){
                    count++;
                    BFS(adj,v,visited);
                }
            }
        }
        return count ;
    }
};