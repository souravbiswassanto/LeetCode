class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r){
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }
        int a, b; if(nums.size() and l < nums.size() and nums[l] == target) a = l; else a = -1;
        l = 0, r = nums.size() - 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        if(l > 0 and nums[l - 1] == target) b = l - 1;
        else b = -1; vector<int>v; v.push_back(a), v.push_back(b);
        return v;
    }
};