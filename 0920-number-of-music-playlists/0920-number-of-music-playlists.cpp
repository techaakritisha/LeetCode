class Solution {
public:
    int N ,K ,G;
    const int mod = 1e9+7;
    long t[101][101];
    long solve(int count_song , int count_uniq){
        if(count_song == G){
            if(count_uniq == N)
                 return 1;
            
            return 0;
        }
        
        if(t[count_song][count_uniq] != -1)
             return t[count_song][count_uniq];
        
        long result = 0;
        
        //Play Unique Songs
        if(N > count_uniq) {
            result += (N-count_uniq) * solve(count_song+1 , count_uniq+1);
        }
        
        
        //Replay a Song
        if(K < count_uniq) {
            result += (count_uniq - K) * solve(count_song+1,count_uniq);
        }
    
        return t[count_song][count_uniq] = result%mod;
        
    }
    int numMusicPlaylists(int n, int goal, int k) {
        N = n;
        K = k;
        G = goal;
        
        memset(t,-1,sizeof(t));
        return solve(0,0);
    }
};