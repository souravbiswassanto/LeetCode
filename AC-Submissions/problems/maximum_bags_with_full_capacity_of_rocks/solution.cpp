class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for (int i = 0; i < n; i++) {
            capacity[i] = capacity[i] - rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (capacity[i] > additionalRocks) break;
            ans++;
            additionalRocks -= capacity[i];
        }
        return ans;
    }
};