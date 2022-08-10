/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        function<TreeNode*(int, int)> solve = [&] (int b, int e) {
            TreeNode* node = new TreeNode(nums[(b + e)/2]);
            if(b == e) {
                node -> val = nums[b];
                return node;
            }
            int mid = (b + e) / 2;
            
            if (b <= mid - 1) node -> left = solve(b, mid - 1);
            if (e >= mid + 1) node->right = solve(mid + 1, e);
            return node;
        };
        return solve(0, nums.size() - 1);
    }
};