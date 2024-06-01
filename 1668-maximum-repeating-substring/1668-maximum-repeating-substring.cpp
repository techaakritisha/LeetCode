class Solution {
public:
    int maxRepeating(string seq, string word) {
        int count = 0;
        string repeated = word;
        while (seq.find(repeated)!=string::npos) {
            count++;
            repeated += word;
        }
        return count;
    }
};