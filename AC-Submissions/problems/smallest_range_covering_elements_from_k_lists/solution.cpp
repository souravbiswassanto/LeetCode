class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        int cnt[n + 4] ;
        for(int i = 0; i < n; i++){
            cnt[i] = 0;
            for(int j = 0; j < nums[i].size(); j++){
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(), v.end()); vector<int> ans(2);
        int a, b, l = 0, cntr = 0, res = INT_MAX;
        for(int i = 0; i < v.size(); i++){
            int val = v[i].first;
            int Index = v[i].second;
            if(cnt[Index] == 0)cntr++;
            if(cntr == n){
                a = i; break; 
            }
            cnt[Index]++;
        }
        for(int i = a; i < v.size(); i++){
            int val = v[i].second;
            cnt[val]++;
            while(l < i and cnt[v[l].second] > 1){
                cnt[v[l].second]--;
                l++;
            }
            if(res > v[i].first - v[l].first){
                res = v[i].first - v[l].first;
                ans[0] = v[l].first;
                ans[1] = v[i].first;
            }
        }
        return ans;
    }
};