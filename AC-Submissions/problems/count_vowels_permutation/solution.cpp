class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        int mod = 1e9 + 7;
        int dp[n + 3][6];
        memset(dp, -1, sizeof dp);
        function<int(int, int)> calc = [&] (int i, int cur){
            if(i == n - 1) {
                return 1;
            }
            int& ret = dp[i][cur];
            if (ret != -1) return ret;
            ret = 0;
            if(cur == 1) {
                ret = calc(i + 1, 2); 
            }
            if(cur == 2){
                ret += calc(i + 1, 1); ret %= mod;
                ret += calc(i + 1, 3); ret %= mod;
            }
            if(cur == 3) {
                ret += calc(i + 1, 1); ret %= mod;
                ret += calc(i + 1, 2); ret %= mod;
                ret += calc(i + 1, 4); ret %= mod;
                ret += calc(i + 1, 5); ret %= mod;
            }
            if(cur == 4){
                ret += calc(i + 1, 3); ret %= mod;
                ret += calc(i + 1, 5); ret %= mod;
            }
            if(cur == 5) ret = calc(i + 1, 1);
            ret %= mod;
            return ret;
        };
        
        int ans = 0;
        for(int i = 1; i <= 5; i++) {
            ans = (ans + calc(0, i)) % mod;
        }
        return ans;
    }
};