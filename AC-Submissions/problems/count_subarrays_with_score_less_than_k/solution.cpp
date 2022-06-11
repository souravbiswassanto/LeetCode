class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l= 0;
        int n = nums.size();
        long long ans = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(l <= i and (sum * 1LL * (i - l + 1)) >= k){
                sum -= nums[l];
                l++;
            }
            if(l <= i){
                ans += (i - l + 1);
            }
        }
        return ans;
    }
};