#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        oset<int> S;
        for (int i = 0; i < k; i++) {
            S.insert(nums[i]);
        }
        vector<double> res;
        if (k % 2) res.push_back(*S.find_by_order(k / 2) * 1.0);
        else {
            double x = (*S.find_by_order(k/2)*1.0 + *S.find_by_order(k/2-1) * 1.0)/2.0;
            res.push_back(x);
        }
        int n = nums.size();
        for (int i = k; i < n; i++){
            S.erase(S.find_by_order(S.order_of_key(nums[i - k])));
            S.insert(nums[i]);
            if (k % 2) res.push_back(*S.find_by_order(k / 2) * 1.0);
            else {
                double x = (*S.find_by_order(k/2) * 1.0 + 1.0 * *S.find_by_order(k/2-1))/2.0;
                res.push_back(x);
            }
        }
        return res;
    }
};