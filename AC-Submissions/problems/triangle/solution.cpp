class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[201][201];
        for(int i = 0; i < 200; i++){
            for(int j = 0; j < 200; j++){
                dp[i][j] = 10000000;
            }
        }
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j)dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                dp[i][j] = min(dp[i][j], dp[i-1][j] + triangle[i][j]);
            }
        }
        int Min = INT_MAX;
        for(int i = 0; i < triangle.size(); i++){
            Min = min(Min, dp[triangle.size()- 1][i]);
        }
        return Min;
    }
};