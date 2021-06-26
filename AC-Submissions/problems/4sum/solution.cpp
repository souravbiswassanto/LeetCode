class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l, r;
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        set<pair<pair<int, int>, pair<int, int>>> Res;
        for(int i = 0; i <= n - 4; i++){
            for(int j = i + 1; j < n - 2; j++){
                l = j + 1;
                r = n - 1;
                long long sum = nums[i] + nums[j];
                long long need =  target - sum;
                while(l < r){
                    long long tsum = nums[l] + nums[r];
                    
                    if(tsum > need){
                        r--;
                    }
                    else if(tsum < need){
                        l++;
                    }
                    else{
                        vector<int> V;
                        V.push_back(nums[i]);
                        V.push_back(nums[j]);
                        V.push_back(nums[l]);
                        V.push_back(nums[r]);
                        sort(V.begin(), V.end());
                        //res.push_back(V);
                        Res.insert({{V[0], V[1]},{V[2], V[3]}});
                        
                        l++; r--;
                        
                    }
                }
            }
        }
        for(auto it: Res){
            vector<int> V;
            V.push_back(it.first.first);
            V.push_back(it.first.second);
            V.push_back(it.second.first);
            V.push_back(it.second.second);
            res.push_back(V);
        }
        return res;
    }
};