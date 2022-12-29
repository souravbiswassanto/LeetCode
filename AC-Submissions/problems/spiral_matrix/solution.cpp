#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rmn = 0, rmx = n - 1;
        int cmn = 0, cmx = m - 1;
        vector<int> res;
        
        while(rmn <= rmx and cmn <= cmx) {
            if (rmx == rmn) {
                for (int i = cmn; i <= cmx; i++) {
                    res.pb(matrix[rmn][i]);
                }
            }
            else if(cmx == cmn) {
                for (int i = rmn; i <= rmx; i++){
                    res.pb(matrix[i][cmn]);
                }
            }
            else {
                for (int i = cmn; i <= cmx; i++) {
                    res.pb(matrix[rmn][i]);
                }
                for (int i = rmn + 1; i < rmx; i++){
                    res.pb(matrix[i][cmx]);
                }
                for (int i = cmx; i >= cmn; i--) {
                    res.pb(matrix[rmx][i]);
                }
                for (int i = rmx - 1; i > rmn; i--){
                    res.pb(matrix[i][cmn]);
                }
            }
            
            rmn++, cmn++, rmx--, cmx--;
            //for (auto it: res) cout << it <<" "; cout << endl;
        }
        return res;
    }
};