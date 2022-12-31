class Solution {
public:
    int ans = 0, totalZeroCell, count;
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size()) return;
        if (vis[x][y] == 1) return;
        if(grid[x][y] == -1) return;
        if (grid[x][y] == 2) {
            if (count == totalZeroCell) ans++;
            return;
        }
        
        if (grid[x][y] == 0) count++;
        vis[x][y] = 1;
        dfs(x, y + 1, grid, vis);
        dfs(x, y - 1, grid, vis);
        dfs(x + 1, y, grid, vis);
        dfs(x - 1, y, grid, vis);
        vis[x][y] = 0;
        if (grid[x][y] == 0) count--;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j= 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x = i; y = j;
                }
                if (grid[i][j] == 0) totalZeroCell++;
            }
        }
        dfs(x, y, grid, vis);
        return ans;
    }
};