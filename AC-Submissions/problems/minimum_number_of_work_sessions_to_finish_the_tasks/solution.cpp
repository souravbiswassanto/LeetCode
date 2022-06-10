class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int dp[1 << n][16];
        memset(dp, -1, sizeof dp);
        function<int(int, int)> calc = [&](int mask, int k){
            if((1<<n) - 1 == mask)return 0;
            int &ret = dp[mask][k];
            if(ret != -1)return ret;
            ret = INT_MAX - 100; bool check = false;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i))continue;
                if(k >= tasks[i])check = 1;
            }
            if(check == false)k = sessionTime;
            for(int i = 0; i < n; i++){
                if(tasks[i] > k)continue;
                if(mask & (1 << i))continue;
                ret = min(ret, calc(mask | (1 << i), k - tasks[i]));
            }
            if(!check)ret++;
            return ret;
        };
        int ans = calc(0, sessionTime);
        return ans + 1;
    }
};