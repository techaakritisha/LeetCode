class Solution {
public:
    /*
   bool solve(unordered_map<int,vector<int>> adj,int n, vector<int> deg) {
       queue<int> q;
       int count = 0;
       for(int i=0;i <n; i++) {
           if(deg[i] == 0) {
               count++;
               q.push(i);
           }
       }
       
       while(!q.empty()){
           int u = q.front();
           q.pop();
           
           for(int &v : adj[u] ){
               deg[v]--;
            if(deg[v] == 0 ) {
              count++;
                q.push(v);
           }
           }
       }
               
               if(count  == n )
                return true;
               
               
             return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> deg(numCourses,0);
        
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            
            adj[b].push_back(a);
            deg[a]++;
        }
        return solve(adj,numCourses,deg);
        
        */
    
       //  Using DFS
      bool DFS( unordered_map<int,vector<int>> &adj,int u , vector<bool> &visited , vector<bool> &rec) {
          visited[u] = true;
          rec[u] = true;
          
          for(int &v : adj[u]){
              if(!visited[v] && DFS(adj,v,visited,rec)){
                  return true;
              }
              if(rec[v] == true){
                  return true;
              }
          }
          rec[u] = false;
          return false;
      }
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
          
            unordered_map<int,vector<int>> adj;
           
           for(auto &pre : prerequisites){
               int a = pre[0];
               int b = pre[1];
               
               adj[b].push_back(a);
               
           }
          
          vector<bool> visited(numCourses,false);
          vector<bool> recur(numCourses,false);
          
          for(int i=0; i<numCourses; i++){
              if(!visited[i] && DFS(adj,i,visited,recur)){
                  return false;
              }
          }
        return true;
    }
};