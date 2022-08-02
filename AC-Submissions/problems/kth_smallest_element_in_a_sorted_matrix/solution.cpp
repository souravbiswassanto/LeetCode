class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = -1e9 - 1;
        int r = 1e9 + 1;
        int n = matrix.size();
        int sum;
        while(l <= r){
            int mid = (l + r) / 2;
            sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(sum >= k) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};