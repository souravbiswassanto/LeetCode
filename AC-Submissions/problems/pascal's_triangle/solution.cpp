class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        vector<int> v; v.push_back(1);
        pascalTriangle.push_back(v);
        for(int i = 1; i < numRows; i++){
            vector<int> newvector;
            for(int j = 0; j <= pascalTriangle[i-1].size(); j++){
                int a, b;
                if(j - 1 < 0)a = 0;
                else a = pascalTriangle[i-1][j - 1];
                if(j == pascalTriangle[i - 1].size())b = 0;
                else b = pascalTriangle[i - 1][j];
                newvector.push_back(a + b);
            }
            pascalTriangle.push_back(newvector);
        }
        return pascalTriangle;
    }
};