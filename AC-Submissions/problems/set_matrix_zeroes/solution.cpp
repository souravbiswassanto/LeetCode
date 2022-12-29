class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool check1 = false, check2 = false;
        for (int i = 0; i < n; i++) { 
            for(int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) check1 = true;
                    if (j == 0) check2 = true;
                    if(i == 0 and j == 0) continue;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) matrix[i][j] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < n; j++) matrix[j][i] = 0;
            }
        }
        
        if(check2) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
        if (check1) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        //return matrix;
    }
};