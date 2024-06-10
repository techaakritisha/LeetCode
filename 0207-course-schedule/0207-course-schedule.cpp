class Solution {
public:
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
    }
};