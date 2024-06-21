class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int curr = 0;
        int n = customers.size();
        
        for(int i=0; i<minutes; i++){
            curr += customers[i]*grumpy[i] ;
        }
        
        int maxi = curr;
        int i = 0;
        int j = minutes;
        
        while(j < n) {
            curr += customers[j] * grumpy[j];
            curr -= customers[i] * grumpy[i];
            
            maxi = max(maxi,curr);
            
            i++;
            j++;
        }
        
        int total = maxi;
        
        for(int i=0; i<n; i++) {
            total += customers[i] * (1-grumpy[i]);
        }
        return total;
    }
};