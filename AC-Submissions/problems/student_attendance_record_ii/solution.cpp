class Solution {
public:
    int checkRecord(int n) {
        int dp[n + 3][3][2]; int mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        
        function<int(int, int, int)> calc = [&] (int i, int late, int absent) {
            if(i == n) return 1;
            int &ret = dp[i][late][absent];
            if (ret != -1) return ret % mod;
            ret = 0;
            if(!absent) {
                (ret += calc(i + 1, 0, 1)) %= mod;
            }
            if(late != 2) {
                (ret += calc(i + 1, late + 1, absent)) %= mod;
            }
            (ret += calc(i + 1, 0, absent)) %= mod;
            
            return ret;
        };
        
        int ans = calc(0, 0, 0) % mod;
        return ans;
    }
};