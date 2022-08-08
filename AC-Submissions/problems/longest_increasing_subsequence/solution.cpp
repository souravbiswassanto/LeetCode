class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for(auto num: nums) {
            int id = lower_bound(LIS.begin(), LIS.end(), num) - LIS.begin();
            if (id == LIS.size()) LIS.push_back(num);
            else LIS[id] = num;
        }
        
        return LIS.size();
        
    }
};