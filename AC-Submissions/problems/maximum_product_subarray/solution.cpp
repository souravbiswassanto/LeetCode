class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l, r;
        l = 0, r = 0;
        int mul = 1, smul, Max = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            Max = max(Max, nums[i]);
        }
        nums.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 and (i - l) > 1){
                cout << i << endl;
                if(mul < 0){
                    smul = 1; r = i - 1;
                    while(r >= l and nums[r] >= 0){
                        smul *= nums[r--];
                    }
                    smul *= nums[r];
                    //cout << nums[r] << endl;
                    if(r - l > 1)Max = max(Max, mul / smul);
                    smul = 1;
                    while(l <= i and nums[l] >= 0){
                        smul *= nums[l++];
                    }
                    smul *= nums[l];
                    //cout << nums[l] << endl;
                    if(i - l > 1)Max = max(Max, mul / smul);
                }
                if(mul >= 1 and (i - l) > 1)Max = max(mul, Max);
                
            }
            else mul *= nums[i];
            if(nums[i] == 0){
                l = i + 1;
                mul = 1;
            }
        }
        return Max;
        
    }
};