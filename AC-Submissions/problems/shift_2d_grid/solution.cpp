class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int> (m,0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int a = cnt++;
                a += k; a %= (n * m);
                int nx = a / m; 
                int ny = a % m;
                //cout <<a<<" "<< nx <<" "<< ny << endl;
                res[nx][ny] = grid[i][j];
            }
        }
        //return 1;
        return res;
    }
};