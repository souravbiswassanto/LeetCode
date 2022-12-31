class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> results;
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if (nums[num - 1] < 0) {
                results.push_back(num);
            }
            else {
                nums[num - 1] *= -1;
            }
        }
        return results;
    }
};