class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m]; memset(vis, 0, sizeof vis);
        pair<long long, long long> dp[n][m];
        if(grid[0][0] == 0 or grid[n - 1][m - 1] == 0)return 0;
        function <pair<long long, long long>(int, int)> bt = [&](int i, int j){
            
            if(i == n -1 and j == m - 1){
                return make_pair(1LL * grid[i][j],1LL* grid[i][j]);
            }
            if(vis[i][j])return dp[i][j];
            vis[i][j] = true;
            pair<long long, long> F , S;
            if(i < n - 1 and j < m - 1){
                F = bt(i + 1, j);
                dp[i][j].first = max(grid[i][j] * 1LL * F.first, grid[i][j] * 1LL * F.second);
                dp[i][j].second = min(grid[i][j] * 1LL * F.first, grid[i][j] * 1LL * F.second);
                S = bt(i, j + 1);
                dp[i][j].first = max(dp[i][j].first, max(grid[i][j] * 1LL * S.first, grid[i][j] * 1LL * S.second));            
                dp[i][j].second = min(dp[i][j].second, min(grid[i][j] * 1LL * S.first, grid[i][j] * 1LL * S.second));
            } 
            else if(j < m - 1){
                S = bt(i, j + 1);
                dp[i][j].first = max(grid[i][j] * 1LL * S.first, grid[i][j] * 1LL * S.second);            
                dp[i][j].second = min(grid[i][j] * 1LL * S.first, grid[i][j] * 1LL * S.second);
            }
            else if(i < n - 1){
                F = bt(i + 1, j);
                dp[i][j].first = max(grid[i][j] * 1LL * F.first, grid[i][j] * 1LL * F.second);
                dp[i][j].second = min(grid[i][j] * 1LL * F.first, grid[i][j] * 1LL * F.second);
            }
            
            return dp[i][j];
        };
        pair<long long, long long> ans = bt(0, 0);
        for(int i = 0; i < n; i++){
            //for(int j = 0; j < m; j++)cout << i <<" " << j <<" " << dp[i][j].first <<" "<< dp[i][j].second << endl;
        }
        if(ans.first < 0)return -1;
        return ans.first % 1000000007;
    }
};