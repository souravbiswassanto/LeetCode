class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int dp[1002][2];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        dp[0][1] = 1; int Max = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] > nums[i])dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                if(nums[j] < nums[i])dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                
            }
            Max = max(Max, dp[i][0]);
            Max = max(Max, dp[i][1]);
        }
        return Max;
    }
};