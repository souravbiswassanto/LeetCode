class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        int mx = n - 1;
        int ans = 1;
        for (int i = 0; i < n; i++) {    
            while(mx >= i + 1 and nums[i] != i + 1)  {
                if (nums[i] <= i or nums[i] > mx) {
                    swap(nums[i], nums[mx]);
                    mx--;
                    // eikhane nums[i] <= i hoile seitare bad dia disi.
                }
                else if(nums[i] == nums[nums[i]]) {
                    swap(nums[nums[i]], nums[mx]); mx--;
                    // ei condition ta extra lagse ei type er case er jonno, [2, 2, 2, 2]
                    // ei case er jnno tle hoia jai. er jonno duita swap same hoile samner tare bair
                    // kore disi.
                }
                else {
                    swap(nums[i], nums[nums[i]]);
                }
            }
            if(nums[i] == i + 1) ans = i + 2;
            else ans = i + 1;
            if(nums[i] != i + 1) break;
        }
        return ans;
    }
};