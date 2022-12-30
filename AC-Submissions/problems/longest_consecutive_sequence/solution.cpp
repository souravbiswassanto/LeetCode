class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashMap, secondHashMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hashMap[nums[i]] = 1;
        }
        for(int i = 0; i < n; i++) {
            if(secondHashMap[nums[i]] != 0)continue;
            int cntr = nums[i];
            while(secondHashMap[cntr] == 0 and hashMap[cntr]) {
                secondHashMap[nums[i]]++;
                secondHashMap[cntr] = 1;
                cntr++;
            }
            secondHashMap[nums[i]] += secondHashMap[cntr];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, secondHashMap[nums[i]]);
        }
        return ans;
    }
};