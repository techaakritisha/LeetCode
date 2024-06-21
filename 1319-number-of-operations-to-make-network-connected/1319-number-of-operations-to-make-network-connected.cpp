class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x) 
             return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x , int y) {
        int parentx = find(x);
        int parenty = find(y);
        
        if(parentx == parenty)
            return;
        
        if(rank[parentx] > rank[parenty]) {
            parent[parentx] = parenty;
        }
        
        if(rank[parentx] < rank[parenty]){
            parent[parenty] = parentx;
        }
        else{
            parent[parentx] = parenty;
            rank[parenty]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        
        if(connections.size() < n-1)
            return -1;
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        int components = n;
        
        
        for(auto &vec : connections) {
            if(find(vec[0]) != find(vec[1])){
                Union(vec[0],vec[1]);
                
                components--;
            }
        }
        return components-1;
    }
};