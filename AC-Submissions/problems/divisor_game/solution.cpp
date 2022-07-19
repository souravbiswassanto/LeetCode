class Solution {
public:
    bool divisorGame(int n) {
        int dp[n + 3];
        memset(dp, -1, sizeof dp);
        function<int(int)> canwin = [&](int this_n){
            if(this_n == 1)return 1;
            int &ret = dp[this_n];
            if(ret != -1)return (1 - ret);
            ret = 0;
            for(int i = 1; i < this_n; i++){
                if(this_n % i == 0)ret |= canwin(this_n - i);
            }
            return 1 - ret;
        };
        int ans = canwin(n);
        if(ans)return false;
        else return true;
    }
};