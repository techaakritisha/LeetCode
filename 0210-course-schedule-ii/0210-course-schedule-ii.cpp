class Solution {
public:
    bool cycle;
    void solve(unordered_map<int,vector<int>> &adj,int u ,stack<int> &st,vector<bool> &visited , vector<bool> &recur) 
    {
        visited[u] = true;
        recur[u] = true;
        
        for(int &v : adj[u]) {
            if(!visited[v]){
                solve(adj,v,st,visited,recur);
            }
            if(recur[v] == true){
                cycle = true;
                return;
            }
        }
        st.push(u);
        recur[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        
        for(auto &pre:prerequisites){
            int a = pre[0];
            int b = pre[1];
            
            adj[b].push_back(a);
        }
        
        vector<bool> visited(numCourses,false);
        vector<bool> recur(numCourses,false);
        
        stack<int> st;
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                solve(adj,i,st,visited,recur);
            }
        }
         
        if(cycle == true){
            return {};
        }
        
        vector<int> result;
        
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};