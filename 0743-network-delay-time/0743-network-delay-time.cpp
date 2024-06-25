class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int time = vec[2];
            
            adj[u].push_back({v,time});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(n+1,INT_MAX);
        
        result[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()) {
           int time = pq.top().first;
           int node = pq.top().second;
           
           pq.pop();
           
           for(auto &it : adj[node]) {
                int adjnode = it.first;
                int t = it.second;
               
               if(time+t < result[adjnode]){
                   result[adjnode] = t + time;
                   pq.push({time+t,adjnode});
               }
           }
        } 
        
        int ans = INT_MIN;
        
        for(int i=1; i<=n; i++){
            ans = max(ans,result[i]);
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};