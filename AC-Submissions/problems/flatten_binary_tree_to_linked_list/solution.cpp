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
    void flatten(TreeNode* root) {
        TreeNode* Last = NULL;
        
        function<void(TreeNode*)> dfsRightOrder = [&](TreeNode* cur){
            if(cur == NULL)return;
            dfsRightOrder(cur->right);
            dfsRightOrder(cur->left);
            cur->right = Last;
            cur->left = NULL;
            Last = cur;
        };
        dfsRightOrder(root);
    }
};