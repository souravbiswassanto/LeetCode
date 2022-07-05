class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m1, m2;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i]++;
            m1[nums[i]] = 1;
        }
        int res, mx = 0;
        for(int i = 0; i < n; i++){
            if(m2[nums[i]])continue;
            res = nums[i];
            for(int j = nums[i]; m1[j]; j++){
                if(m2[j] != 0){
                    res = m2[j]; break;
                }
                res = j;
            }
            m2[nums[i]] = res;
            mx = max(mx, res - nums[i] + 1);
            //cout << nums[i] <<" " << res << endl;
        }
        return mx;
    }
};