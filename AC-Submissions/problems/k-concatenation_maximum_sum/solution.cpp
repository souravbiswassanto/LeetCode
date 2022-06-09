class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int Max = 0, Max1 = 0, sum = 0, tot = 0;
        int n = arr.size();
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i]; tot += arr[i];
            Max = max(Max, sum);
            if(sum < 0)sum = 0;
        } Max1 = Max;
        if(k == 1){
            return Max;
        }
        sum = 0;
        for(int i = 0; i < 2 * n; i++){
            sum += arr[i % n];
            Max = max(Max, sum);
            if(sum < 0)sum = 0;
        }
        Max = Max % 1000000007;
        if(tot < 0)return Max;
        int dp[k + 4];
        dp[1] = Max1;
        for(int i = 2; i <= k; i++){
            dp[i] = dp[i - 1] + tot;
            dp[i] %= 1000000007;
        }
        return max(Max, dp[k]);
    }
};