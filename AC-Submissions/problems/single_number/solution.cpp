class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) nums[i] = nums[i - 1] ^ nums[i];
        return nums[nums.size() - 1];
    }
};