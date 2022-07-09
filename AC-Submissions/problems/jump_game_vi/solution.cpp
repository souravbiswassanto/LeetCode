class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_front(0);
        int n = nums.size();
        int ans;
        int dp[n + 2];
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            while(!dq.empty() and dq.back()+ k < i)dq.pop_back();
            int a = dp[dq.back()] + nums[i];
            while(!dq.empty() and dp[dq.front()] <= a)dq.pop_front();
            dq.push_front(i);
            dp[i] = a;
            if(i == n - 1)ans = a;
        }
        return dp[n - 1];
    }
};