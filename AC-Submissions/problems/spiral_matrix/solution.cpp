#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> newmat(n + 2, vector<int> (m + 2, 1)), Mat(n + 2, vector<int> (m + 2));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                newmat[i][j] = 0;
                Mat[i][j] = matrix[i - 1][j - 1];
            }
        }
        int i = 1, j = 1; vector<int> v;
        while(newmat[i][j] != 1){
            
            while(newmat[i][j] != 1){
                v.pb(Mat[i][j]);
                newmat[i][j] = 1;
                j++;
            }
            j--; i++;
            cout << i <<" "<< j << endl;
            while(newmat[i][j] != 1){
                v.pb(Mat[i][j]);
                newmat[i][j] = 1;
                i++;
            }
            i--; j--;
            cout << i <<" "<< j << endl;
            
            while(newmat[i][j] != 1){
                v.pb(Mat[i][j]);
                newmat[i][j] = 1;
                j--;
            }
            j++; i--;
            cout << i <<" "<< j << endl;
            while(newmat[i][j] != 1){
                v.pb(Mat[i][j]);
                newmat[i][j] = 1;
                i--;
            }
            i++; j++;
            cout << i <<" "<< j << endl;
        }
        return v;
        
    }
};