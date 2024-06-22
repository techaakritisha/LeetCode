class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
      if(parent[x] == x)
           return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int a , int b) {
        int parent_a = find(a);
        int parent_b = find(b);
        
        if(parent_a == parent_b)
             return ;
        
        if(rank[parent_a] > rank[parent_b]){
            parent[parent_a] = parent_b;
        }
        
        if(rank[parent_a] < rank[parent_b]){
            parent[parent_b] = parent_a;
        }
        else{
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            Union(u,v);
        }
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            int p = find(i);
            mp[p]++;
        }
        
        long long ans = 0;
        long long remain = n;
        
        for(auto &it : mp) {
            long long size = it.second;
            
            ans += (size) * (remain-size);
            
            remain -= size;
        }
        return ans;
    }
};