class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[m + 2][target + 2][n + 2];
        memset(dp, -1, sizeof dp);
        
        function<int(int, int, int)> calc =[&](int idx, int t, int last){
            if(idx == m){
                if(target == t + 1)return 0;
                return 30000000;
            }
            if(t >= target)return 30000000;
            if(m - idx + t + 1< target)return 30000000;
            int &ret = dp[idx][t][last];
            if(ret != -1)return ret;
            ret = 1000000000;
            if(houses[idx]){
                if(idx == 0)last = houses[idx];
                ret = calc(idx + 1, t + (last != houses[idx]), houses[idx]);
            }
            else{
                for(int i = 1; i <= n; i++){
                    if(idx == 0)last = i;
                    ret = min(ret, calc(idx + 1, t + (last != i), i) + cost[idx][i - 1]);
                }
            }
            return ret;
        };
        int ans = calc(0, 0, 0);
        if(ans > 1e7)return -1;
        return ans;
    }
};