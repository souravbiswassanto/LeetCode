class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); int m = matrix[0].size();
        int matsum[n + 1][m + 1];
        memset(matsum, 0, sizeof matsum); int maxSum =INT_MIN;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                matsum[i][j] = -matsum[i - 1][j - 1] + matsum[i - 1][j] + matsum[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int p = i; p <= n; ++p) {
                    for (int q = j; q <= m; ++q) {
                        int sum = matsum[p][q] - matsum[p][j - 1] - matsum[i - 1][q] + matsum[i - 1][j- 1];
                        //cout << matsum[p][q] <<" " << matsum[p][j-1] <<" " << matsum[i - 1][q] << " " << matsum[i - 1][j - 1] << endl;
                        //cout << i <<" " << j <<" " << p <<" " << q <<" " << sum << endl;
                        if (sum <= k) maxSum = max(maxSum, sum);
                    }
                }
            }
        }
        return maxSum;
    }
};