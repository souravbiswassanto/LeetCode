class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = 0;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] ^ nums[i];
            Xor ^= i;
        }
        Xor ^= nums.size();
        return Xor ^ nums[nums.size() - 1];
    }
};