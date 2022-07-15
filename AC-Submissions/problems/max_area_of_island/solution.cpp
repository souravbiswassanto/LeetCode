class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        int vis[n + 1][m + 1];
        memset(vis, 0, sizeof vis);
        function<int(int, int)> dfs = [&](int x, int y){
            
            if(x < 0 or y < 0 or x == n or y == m)return 0;
            if(vis[x][y] or !grid[x][y])return 0;
            int cur = 1; vis[x][y] = 1;
            cur += dfs(x + 1, y);
            cur += dfs(x - 1, y);
            cur += dfs(x, y + 1);
            cur += dfs(x, y - 1);
            
            return cur;
        };
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 or vis[i][j] == 1)continue;
                maxArea = max(maxArea, dfs(i, j));
                //cout << i <<" " << j <<" " << maxArea << endl;
            }
        }
        return maxArea;
    }
};