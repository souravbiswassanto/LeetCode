class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int fmx = -INT_MAX - 1;
        int neginf = fmx;
        int smx = fmx;
        int tmx = fmx;
        bool check = false;
        
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] == neginf)check = true;
            if(fmx < nums[i]){
                swap(fmx, smx);
                swap(fmx, tmx);
                fmx = nums[i];
            }
            else if(smx < nums[i] and nums[i] != fmx){
                swap(smx, tmx);
                smx = nums[i];
            }
            else if(tmx < nums[i] and nums[i] != fmx and nums[i] != smx){
                tmx = nums[i];
                check = true;
            }
        }
        if(fmx == neginf){
            return fmx;
        }
        else if(smx == neginf)return fmx;
        else{
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == neginf)return tmx;
            }
            if(tmx == neginf)return fmx;
            return tmx;
        }
        
    }
};