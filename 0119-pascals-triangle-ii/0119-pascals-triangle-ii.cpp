class Solution {
public:
    vector<int> getRow(int rowInd) {
        vector<vector<int>> res(rowInd+1);

        for (int i = 0; i < rowInd+1; i++) {
            res[i] = vector<int>(i+1, 1);

            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }

        return res[rowInd];
    }
};