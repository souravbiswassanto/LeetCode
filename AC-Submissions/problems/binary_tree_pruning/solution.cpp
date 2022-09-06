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
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* dummy;
        //dummy->left = root;
        function<bool(TreeNode*, TreeNode*, int)> dfs = [&] (TreeNode* cur,TreeNode* prev, int type) {
            if (cur == NULL) return false;
            bool ans = false;
            ans |= dfs(cur->left, cur, 1);
            ans |= dfs(cur->right, cur, 2);
            ans |= cur->val;
            //cout << ans << endl;
            if (ans == false and type == 1) {
                prev->left = NULL;
            }
            if (ans == false and type == 2) {
                prev->right = NULL;
            }
            return ans;
        };
        bool d = dfs(root, root, 1);
        if (d == false) return NULL;
        return root;
    }
    
};