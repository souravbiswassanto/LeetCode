class Solution {
public:
    int n, m;
    bool vis[6][6], ans;
    
    void bt(int row, int col, int step, string &target, vector<vector<char>>& board) {
        if(step == target.size()){
            ans = true;
        }
        if(ans) return;
        if (row < 0 or col < 0 or row == n or col == m)return;
        if (vis[row][col])return;
        if (target[step] != board[row][col]){
            return;
        }
        vis[row][col] = 1;
        bt(row + 1, col, step + 1, target, board);
        bt(row - 1, col, step + 1, target, board);
        bt(row, col + 1, step + 1, target, board);
        bt(row, col - 1, step + 1, target, board);
        vis[row][col] = 0;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); 
        m = board[0].size();
        memset(vis, 0, sizeof vis);
        ans = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                if(ans == 0) bt(i, j , 0, word, board);
            }
        }
        return ans;
    }
};