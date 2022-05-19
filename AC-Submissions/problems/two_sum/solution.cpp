class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, short int> M; vector<int> res; 
        for(int i = 0; i < nums.size(); i++){
            int a = target - nums[i];
            if(M.find(a) != M.end()){
                res.push_back(M[a] - 1);
                res.push_back(i);
                break;
            }
            M[nums[i]] = i + 1;
        }
        return res;
    }
};