class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        bool vis[grid.size()][grid[0].size()];
        memset(vis, 0, sizeof vis);
        int n = grid.size(); int m = grid[0].size();
        function <void(int, int)> dfs = [&] (int x, int y) {
            if (x < 0 or y < 0 or x >= n or y >= m or grid[x][y] == '0') return;
            if (vis[x][y]) return;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                dfs(xx, yy);
            }
        };
        int cntr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if(vis[i][j] == 0 and grid[i][j] == '1'){
                    cntr++;
                    dfs(i, j);
                } 
            }
        }
        return cntr;
    }
};