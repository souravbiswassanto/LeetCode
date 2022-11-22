class Solution {
public:
    int numSquares(int n) {
        int dp[n + 2];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int a = sqrt(i) + 1; dp[i] = INT_MAX;
            for (int j = 1; j <= a; j++) {
                if (i - j * j < 0) break;
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
            //cout << dp[i] << endl;
        }
        return dp[n];
    }
};