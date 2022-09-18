class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); vector<int> L(n), R(n);
        stack<int> S; int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, height[i]);
            L[i] = mx;
        }
        mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, height[i]);
            R[i] = mx;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (max(0, min(R[i], L[i]) - height[i]));
        }
        return sum;
    }
};