class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> L, R; int n = nums.size();
        int l = n, r = -1;
        for (int i = 0; i < n; i++) {
            while(!L.empty() and nums[L.top()] > nums[i]) {
                l = min(l, L.top());
                L.pop();
            }
            L.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while(!R.empty() and nums[R.top()] < nums[i]) {
                r = max(r, R.top());
                R.pop();
            }
            R.push(i);
        }
        if (l == n and r == -1) return 0;
        return max(0, r - l + 1);
    }
};