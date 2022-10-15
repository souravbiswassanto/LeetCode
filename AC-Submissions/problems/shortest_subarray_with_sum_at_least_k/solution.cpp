class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long cum[n + 3];
        cum[0] = 0; int mx = *max_element(nums.begin(), nums.end());
        if (mx >= k) return 1;
        for (int i = 1; i <= n; i++) {
            cum[i] = cum[i - 1] + nums[i - 1];
        }
        int j = 0, ans = INT_MAX;
        deque<int> dq; dq.push_back(0);
        for (int i = 1; i <= n; i++) {
            while(!dq.empty() and cum[dq.back()] >= cum[i]) dq.pop_back();
            while(!dq.empty() and cum[i] - k >= cum[dq.front()]) {
                ans = min(ans, i - dq.front()); dq.pop_front();
            }
            dq.push_back(i);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};