class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int dp[30];
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i < n; i++) {
            int a = s[i] -97; int mx = 0;
            for(int j = 0; j < 26; j++) {
                if(abs(a - j) <= k){
                    mx = max(mx, dp[j]);
                }
            }
            dp[a] = mx + 1;
        }
        int ans = 1;
        for(int i = 0; i < 26; ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};