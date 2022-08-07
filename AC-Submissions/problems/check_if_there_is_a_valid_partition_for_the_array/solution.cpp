class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        bool dp[n + 3];
        for(int i = 0; i < nums.size(); ++i) {
            dp[i] = false;
        }
        dp[n] = true;
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] == nums[i + 1] and dp[i + 2]) dp[i] = true;
            if(i + 2 < n and nums[i] == nums[i + 1] and nums[i] == nums[i + 2] and dp[i + 3]) dp[i] = true;
            if(i + 2 < n and nums[i] + 1== nums[i + 1] and nums[i] + 2 == nums[i + 2] and dp[i + 3]) dp[i] = true;
        }
        return dp[0];
    }
};