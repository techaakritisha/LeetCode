class Solution {
public:
   int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int t[5001][10];
    
    int solve(int n, int cell) {
        if(n == 0) {
            return 1;
        }
        
        if(t[n][cell] != -1) {
            return t[n][cell];
        }
        
        int result = 0;
        
        for(int &nextCell : adj[cell]) {
            result = (result + solve(n-1, nextCell)) % M; 
        }
        
        return t[n][cell] = result;
    }
    
    int knightDialer(int n) {
            int result = 0;
        memset(t, -1, sizeof(t));
        
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + solve(n-1, cell)) % M;
        }
        
        return result;
    }
};