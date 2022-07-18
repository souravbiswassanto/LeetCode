class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int matsum[n + 2][m + 2];
        memset(matsum, 0, sizeof matsum);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                matsum[i][j] = matsum[i - 1][j] + matsum[i][j - 1] - matsum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = 0;
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= m; y++){
                for(int x1 = x; x1 <= n; x1++){
                    for(int y1 = y; y1 <= m; y1++){
                        int sum = matsum[x1][y1] + matsum[x - 1][y - 1] - matsum[x1][y - 1] - matsum[x - 1][y1];
                        if(sum == target)ans++;
                    }
                }
            }
        }
        return ans;
    }
};