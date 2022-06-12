class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int cnt[10004]; int ans = 0, Max = 0;
        memset(cnt, 0, sizeof cnt);
        int l = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]] == 1) sum += cnt[nums[i]];
            ans += nums[i];
            while(l < i and sum != (i - l + 1)){
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 0)sum--;
                ans -= nums[l];
                l++;
            }
            Max = max(Max, ans);
        }
        return Max;
    }
};