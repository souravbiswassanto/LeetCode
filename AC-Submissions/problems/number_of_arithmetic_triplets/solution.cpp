class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cntr = 0;
        
        for(int i = 1; i < nums.size() - 1; i++) {
            for(int j = i - 1; j >= 0; j--) {
                for(int k = i + 1; k < nums.size(); k++){
                    if(nums[i] - nums[j] == diff and nums[k] - nums[i] == diff)cntr++;
                }
            }
        }
        return cntr;
    }
};