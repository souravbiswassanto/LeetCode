class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = nums.size() - 1, r = nums.size() - 1;
        if(sum < x)return -1;
        if(sum == x)return l + 1;
        while(l >= 0 and sum > x){
            sum -= nums[l]; l--;
        }
        int ans = INT_MAX;
        if(sum == x){
            ans = l + 1;
        }
        int tot = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(tot > x)break;
            tot += nums[i];
            while(l >= 0 and tot + sum > x){
                sum -= nums[l]; l--;
            }
            while(l >= i)sum -= nums[l--];
            if(tot + sum == x){
                ans = min(ans, l + 1 + (int)nums.size() - i);
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};