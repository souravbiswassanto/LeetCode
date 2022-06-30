class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median, n = nums.size();
        if(nums.size() % 2)median = nums[n / 2];
        else median = (nums[n / 2] + nums[n / 2 - 1])/2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += abs(median - nums[i]);
        }
        return sum;
    }
};