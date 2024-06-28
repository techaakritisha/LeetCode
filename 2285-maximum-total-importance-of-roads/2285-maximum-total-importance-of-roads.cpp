class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
          vector<int> deg(n,0);
         
        for(auto &it : roads) {
            int u = it[0];
            int v = it[1];
            
            deg[u]++;
            deg[v]++;
        }
      
        sort(begin(deg),end(deg));
        
        long long val = 1;
        long long sum = 0;
        
        for(int i=0; i<n; i++){
            sum += deg[i] * val;
            val++;
        }
        
        return sum;
    }
};