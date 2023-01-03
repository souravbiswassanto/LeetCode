class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            dp[i] = 100000;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] < 0) break;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
            //cout << dp[i] << endl;
        }
        if(dp[amount] >= 100000) return -1;
        
        return dp[amount];
    }
};