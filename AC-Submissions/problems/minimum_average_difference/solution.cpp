class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sumback = accumulate(nums.begin(), nums.end(), 0LL);
        long long sumfront = 0, a, mn = INT_MAX, ans;
        for (int i = 0; i < n; i++) {
            sumfront += nums[i];
            sumback -= nums[i];
            if (i == n - 1) {
                a = sumfront / n;
            }
            else 
            a = abs(sumfront/(i + 1) - sumback/(n - i - 1));
            if (a < mn) {
                mn = a;
                ans = i;
            }
        }
        return ans;
    }
};