class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1], prev[amount + 1];
        memset(prev, 0, sizeof prev);
        
        memset(dp, 0, sizeof dp);dp[0] = 1;
        sort(coins.begin(), coins.end());
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] < 0) dp[j] = prev[j];
                else {
                    dp[j] = dp[j - coins[i]] + prev[j];
                }
            }
            for (int j = 1; j <= amount; j++) prev[j] = dp[j];
        }
        return dp[amount];
    }
};