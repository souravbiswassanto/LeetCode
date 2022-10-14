class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> S;
        indexDiff = min((int)nums.size() - 1, indexDiff);S.insert(INT_MIN);
        S.insert(INT_MAX);
        for (int i = 0; i < nums.size(); i++) {
            auto it = S.upper_bound(nums[i]);
            int a = *it; it--;
            int b = *it;
            if (a != INT_MAX) if (abs(nums[i] - a) <= valueDiff) return true;
            if (b != INT_MIN) if (abs(nums[i] - b) <= valueDiff) return true;
            if(i - indexDiff >= 0) S.erase(S.find(nums[i - indexDiff]));
            S.insert(nums[i]);
        }
        return false;
    }
};