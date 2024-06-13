class Solution {
public:
    /*
    bool colorDFS(vector<vector<int>>& adj,int u , vector<int> &color , int curr) {
        color[u] = curr;
        
        for(int &v : adj[u]){
            if(color[v] == color[u]){
                return false;
            }
            if(color[v] == -1){
                int c = 1 - curr;
                
                if(colorDFS(adj,v,color,c) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
    
        
        vector<int> color(V,-1);
        
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                 if(colorDFS(graph,i,color,1) == false)
                     return false;
            }
        }
        return true;
        
        */
     bool solveBFS(vector<vector<int>>& adj,int curr , vector<int> &color ,int currcolor) {
         queue<int> q;
         q.push(curr);
         
         color[curr] = currcolor;
         
         while(!q.empty()){
             int u = q.front();
             q.pop();
             
             for(int &v : adj[u]){
                 if(color[v] == color[u]){
                     return false;
                 }
                 if(color[v] == -1){
                     color[v] = 1-color[u];
                     q.push(v);
                 }
             }
         }
         return true;
     }
     bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
         vector<int> color(n,-1);
         
         for(int i=0; i<n; i++){
             if(color[i] == -1){
                 if(solveBFS(graph,i,color,1) == false)
                      return false;
             }
         }
         return true;
    }
};