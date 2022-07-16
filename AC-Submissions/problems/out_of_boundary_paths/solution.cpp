class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1e9 + 7;
        int dp[m + 2][n + 2][53];
        memset(dp, -1, sizeof dp);
        function<int(int, int, int)> dfs = [&](int i, int j, int moveLeft){
            if(i < 0 or j < 0 or i == m or j == n)return 1;
            int &ret = dp[i][j][moveLeft];
            if(ret != -1)return ret;
            ret = 0;
            if(moveLeft){
                ret = dfs(i + 1, j , moveLeft - 1) % mod;
                ret =(ret + dfs(i - 1, j, moveLeft - 1)) % mod;
                ret = (ret + dfs(i, j + 1, moveLeft - 1)) % mod;
                ret = (ret + dfs(i, j - 1, moveLeft - 1)) % mod;
            }
            return ret % mod;
        };
        int ans = dfs(startRow, startColumn, maxMove);
        return ans;
    }
};