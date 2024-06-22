class Solution {
public:
    /*
    int t[301][11];
    int solve(vector<int> &jd , int n , int idx , int d) {
          
          if(d == 1){ 
             return *max_element(begin(jd),end(jd));
          }
         
        if(t[idx][d] != -1) {
            return t[idx][d];
        }
        int maxd = jd[idx];
        int final = INT_MAX;

        
            Try One by one all possiblities
            1. Take idx wapa job first day
            2. take {idx,idx+1} wala job second day
            3. take {idx , idx+1,idx+2} wala job first day
            . . 
            .
            .
             so on

             then find optimal one out of them
        

       for(int i=idx; i<=n-d; i++) {
         maxd = max(maxd,jd[i]);

          int res = maxd + solve(jd,n,i+1,d-1);
          final = min(final , res);
       }
      return  t[idx][d] = final;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        
        if(n < d)
          return -1;
        
        memset(t,-1,sizeof(t));
        return solve(jd,n,0,d);
    }
    
    */
   int n ;
   int t[301][11];
   int solve(int i,int d, vector<int> &jd) {
       if(d == 1){
          int maxd = jd[i];
            for(int j=i+1; j<n; j++) {
                maxd = max(maxd,jd[j]);
            }
            return maxd;  
       }
       
        if(n < d) {
           return -1;
       }
       
       if(t[i][d] != -1)
              return t[i][d];
       
       int maxi = jd[i];
       int result = INT_MAX;
       
       for(int j=i; j<=n-d; j++) {
            maxi = max(maxi,jd[j]);
            
            int ans = maxi + solve(j+1,d-1,jd);
           
            result = min(result,ans);
        }
       
       return t[i][d] =  result;
   }
   int minDifficulty(vector<int>& jd, int d) {
       n = jd.size();
         
       memset(t,-1,sizeof(t));
       return solve(0,d,jd);
   }   
};