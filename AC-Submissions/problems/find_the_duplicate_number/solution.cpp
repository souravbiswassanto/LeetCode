class Solution {
public:
    // solved after seeing the solution
    // https://www.youtube.com/watch?v=LUm2ABqAs1w
    // this video for hare and tortoise
    int findDuplicate(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int max_bit = 0, duplicate = 0;
        for (int i = 0; i < 20; i++) {
            if (mx & (1 << i)) max_bit = i;
        }
        for (int bit = 0; bit <= max_bit; bit++) {
            int base_count = 0, num_count = 0;
            for (int i = 0; i <= n; i++) {
                if (i & (1 << bit)) base_count++;
                if (nums[i] & (1 << bit)) num_count++;
            }
            if (num_count > base_count) duplicate |= (1 << bit);
        }
        return duplicate;
    }
};