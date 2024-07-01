class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
  int count = 0; // Initialize count to keep track of consecutive odd numbers

        for (int num : arr) { 
            if (num % 2 != 0) { 
                count++; 
                if (count == 3) { 
                    return true;
                }
            } else { 
                count = 0;
            }
        }

        return false;
    }
};