class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < min(m - j, n); k++) {
                for (int i = 0; i < n; ++i) {
                    if (i >= n - 1 or j + i >= m - 1) break;
                    if (mat[i][j + i] >= mat[i + 1][j + i + 1]) {
                        swap(mat[i][j + i], mat[i + 1][i + j + 1]);
                    }
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < min(n - i, m); k++) {
                for (int j = 0; j < m; ++j) {
                    if (j >= m - 1 or j + i >= n - 1) break;
                    if (mat[i + j][j] >= mat[i + j + 1][j + 1]) {
                        swap(mat[i + j][j], mat[i + j + 1][j + 1]);
                    }
                }
            }
        }
        
        return mat;
    }
};