class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = matrix[i][j]; matrix[i][j] = INT_MAX;
                if (j) matrix[i][j] = min(matrix[i][j], a + matrix[i -1][j - 1]);
                if (j < n - 1) matrix[i][j] = min(matrix[i][j], a + matrix[i - 1][j + 1]);
                matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + a);
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++) res = min(res, matrix[n - 1][i]);
        return res;
    }
};