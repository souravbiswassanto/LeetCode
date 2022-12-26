class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mn = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= mn) mn = i;
            //cout << mn <<" " << i + nums[i] - 1 << endl;
        }
        //cout << mn << endl;
        return mn == 0;
    }
};