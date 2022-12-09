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
    int ans;
public:
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> left ={root->val, root->val}, right = {root-> val, root-> val}, maxmin;
        if (root -> left != NULL) left = dfs(root->left);
        if (root -> right != NULL) right = dfs(root -> right);
        maxmin.first = max(left.first, right.first);
        maxmin.second = min(left.second, right.second);
        ans = max(ans, abs(root->val - maxmin.first));
        ans = max(ans, abs(root->val - maxmin.second));
        return {max(maxmin.first, root->val), min(maxmin.second, root->val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        pair<int, int> maxmin = dfs(root);

        return ans;
    }
};