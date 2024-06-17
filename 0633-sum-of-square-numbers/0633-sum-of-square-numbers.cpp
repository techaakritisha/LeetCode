class Solution {
public:
    bool judgeSquareSum(int c) {
       
        long long  left = 0;
        long long right = sqrt(c);
        
        while(left <= right) {
            long long  x = left*left + right * right;
            
            if(x == c)  return true;
            if(x > c)  right--;
            else left++;
        }
        return false;
    }
};