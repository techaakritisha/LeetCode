class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int total = numBottles;
        
        while(numBottles >= numExchange) {
            int change = numBottles/numExchange;
            total += change ;
            numBottles = change + (numBottles%numExchange);
        }
        
        return total;
    }
};