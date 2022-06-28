class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int sl, sr;nums.push_back(-INT_MAX);
        while(l <= r){ 
            int mid = (l + r) / 2;
            if(nums[mid] >= nums[0])l = mid + 1;
            else r = mid - 1;
        }
        //cout << l << endl;
        if(target >= nums[0]){
            sl = 0; sr = l - 1;
        }
        else{
            sl = l; sr = nums.size() - 1;
        }
        int ans = -1;
        while(sl <= sr){
            int mid = (sl + sr) / 2;
            if(nums[mid] < target)sl = mid + 1;
            else if(nums[mid] > target) sr = mid - 1;
            else { ans = mid; break;}
        }
        return ans;
    }
};