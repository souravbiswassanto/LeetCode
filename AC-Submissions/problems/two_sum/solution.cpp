class Solution {
public:
    struct val{
        bool first;
        int second;
    };
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, val> m;
        vector<int>res(2);
        int cntr = 0;
        for(auto v:nums){
            
            int rem = target - v;
            if(m[rem].first and m[rem].second != cntr){
                res[0] = cntr;
                res[1] = m[rem].second;
                return res;
            }
            m[v] = {1,cntr++};
        }
       
         return {};
    }
};