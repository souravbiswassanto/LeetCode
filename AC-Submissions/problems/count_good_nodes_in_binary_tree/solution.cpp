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
    int goodNodes(TreeNode* root) {
        function<int(int,TreeNode*)> countGoodNode = [&] (int mx, TreeNode* cur){
            if (cur == NULL) return 0;
            if (cur->val >= mx) return countGoodNode(max(mx, cur->val), cur->left) + countGoodNode(max(mx, cur->val), cur->right) + 1;
            else return countGoodNode(max(mx, cur->val), cur->left) + countGoodNode(max(mx, cur->val), cur->right);
            return 0;
        };
        int ans = countGoodNode(INT_MIN, root);
        return ans;
    }
};