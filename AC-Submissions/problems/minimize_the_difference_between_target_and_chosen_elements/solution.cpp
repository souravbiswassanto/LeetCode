class Solution {
public:
    int dp[71][4901];
    vector<vector<int>> matx;
    int n, m, tgt, Min;
    int calc(int id, int sum){
        if(sum - tgt > Min) return INT_MAX;
        if(id == n){
            Min = min(Min, abs(tgt - sum));
            return abs(tgt - sum);
        }
        int &ret = dp[id][sum];
        if(ret != -1)return ret;
        ret = INT_MAX;
        for(int i = 0; i < m; i++){
            ret = min(ret, calc(id + 1, sum + matx[id][i]));
        }
        return ret;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
         n = mat.size();
         m = mat[0].size();
        tgt = target;
        matx = mat;
        Min = INT_MAX;
        memset(dp, -1, sizeof dp);
        
        
        int ans = calc(0, 0);
        return ans;
    }
};