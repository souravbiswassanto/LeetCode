class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int minPos[101];
        memset(minPos, -1, sizeof minPos);
        int n = temperatures.size();
        vector<int> results(n);
        int mx = *max_element(temperatures.begin(), temperatures.end());
        for (int i = n - 1; i >= 0; i--) {
            int mn = INT_MAX;
            for (int j = temperatures[i] + 1; j <= mx; j++) {
                if (minPos[j] == -1) continue;
                mn = min(mn, minPos[j]);
            }
            if (mn == INT_MAX) results[i] = 0;
            else results[i] = mn - i;
            minPos[temperatures[i]] = i;
        }
        return results;
    }
};