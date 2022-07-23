#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

class BIT {
    public:
    vector<int> bit;
    int n;
    BIT(int _n) {
        n = _n;
        bit.clear();
        bit.resize(n + 2, 0);
    }
    
    int getSmaller(int x) {
        int totalSmaller = 0;
        for(; x; x -= x&-x) {
            totalSmaller += bit[x];
        }
        return totalSmaller;
    }
    void update(int x, int delta) {
        for(; x <= n; x += x&-x)bit[x] += delta;
    }
};

class Solution {
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset<int> S;
        for(int i = 0; i < nums.size(); i++){
            nums[i] += 100001;
        }
        int Min = INT_MAX;
        BIT fenTree(*max_element(nums.begin(), nums.end()));
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            Min = min(Min, nums[i]);
            if(Min == nums[i]){
                ans[i] = 0; 
                fenTree.update(nums[i], 1);
                continue;
            }
            ans[i] = fenTree.getSmaller(nums[i] - 1);
            fenTree.update(nums[i], 1);
        }
        return ans;
    }
};

