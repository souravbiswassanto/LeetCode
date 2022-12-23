class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j > 1) dp[i] = max(dp[i], prices[i] - prices[j] + dp[j - 2]);
                else dp[i] = max(dp[i], prices[i] - prices[j]);
            }
            for (int j = i - 1; j >= 0; j--) dp[i] = max(dp[i], dp[j]);
            //cout << dp[i] << endl;
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, dp[i]);
        return res;
    }
};