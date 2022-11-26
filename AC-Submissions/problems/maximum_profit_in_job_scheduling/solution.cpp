#define pb push_back
class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int, pair<int, int>>> vp;
        int n = startTime.size();
        for (int i = 0; i < n; i++){
            vp.pb({endTime[i], {startTime[i], profit[i]}});
        }
        vp.pb({-1, {0, 0}});
        vp.pb({INT_MAX, {0, 0}});
        sort(vp.begin(), vp.end());
        
        int dp[n + 1]; memset(dp, 0, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            int pos = upper_bound(vp.begin(), vp.end(), make_pair(vp[i].second.first, make_pair(INT_MAX, 0))) - vp.begin(); pos--;
            dp[i] = max(dp[i - 1], dp[pos] + vp[i].second.second);
            
        }
        return dp[n];
    }
};