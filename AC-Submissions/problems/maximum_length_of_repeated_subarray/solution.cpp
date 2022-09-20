#define ull unsigned int
#define prime 233
class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size();
        unordered_set<ull> S[1003];
        vector<ull> M[1003];
        int maxRes = 0;
        
        for (int i = 0; i < n; ++i) {
            ull hash = 0; ull pwr = 1;
            for (int j = i; j < n; ++j) {
                hash += (nums1[j] * pwr);
                pwr *= prime;
                M[j -i].push_back(hash);
                //S[j - i].insert(hash);
            }
        }
        for(int i = 0; i < 1001; i++) sort(M[i].begin(), M[i].end());
        for (int i = 0; i < m; ++i) {
            ull hash = 0; ull pwr = 1;
            for (int j = i; j < m; ++j) {
                hash += (nums2[j] * pwr);
                pwr *= prime;
                if (binary_search(M[j - i].begin(), M[j - i].end(), hash)) maxRes= max(maxRes, j - i + 1);
            }
        }
        
        
        return maxRes;
    }
};