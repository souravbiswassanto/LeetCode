class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 10];
        memset(dp, -1, sizeof dp);
        
        function<int(int)> calc = [&](int sum){
            if (sum > target) return 0;
            if (sum == target) return 1;
            int &ret = dp[sum];
            if (ret != -1) return ret;
            ret = 0;
            for (int i = 0; i < nums.size(); ++i) {
                ret += calc(sum + nums[i]);
            }
            return ret;
        };
        int ans = calc(0);
        return ans;
    }
};