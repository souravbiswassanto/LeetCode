class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        set<pair<int, pair<int, int>>> Set;
        for(int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            
            while(l < r){
                
                if(nums[l] + nums[r] > -nums[i]){
                    r--;
                }
                else if(nums[l] + nums[r] < -nums[i]){
                    l++;
                }
                else {
                    Set.insert({nums[i],{ nums[l], nums[r]}});
                    l++; r--;
                }
            }
        }
        vector<vector<int> > Res;
        int i = 0;
        for(auto it: Set){
            vector<int> _3num;
            _3num.push_back(it.first);
            _3num.push_back(it.second.first);
            _3num.push_back(it.second.second);
            sort(_3num.begin(), _3num.end());
            Res.push_back(_3num);
        }
        return Res;
    }
};