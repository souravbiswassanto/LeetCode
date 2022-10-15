class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int b) {
        const int k = b;
        int n = grid.size();
        int m = grid[0].size();
        int dp[n + 2][m + 2][k + 2];
        memset(dp, 0, sizeof dp);
        dp[0][1][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j++) {
                for (int l = 0; l < k; l++) {
                    int x = grid[i - 1][j - 1] + l; x %= k;
                    dp[i][j][x] = (dp[i][j - 1][l] + dp[i - 1][j][l]) % mod;
                }
                
            }
        }
        return dp[n][m][0];
    }
};