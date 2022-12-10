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
    long long int maxAns;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        root->val += dfs(root->left);
        root->val += dfs(root->right);
        return root->val;
    }
    void maxProductDFS(TreeNode* root, int totalSum) {
        if (root == NULL) return;
        maxProductDFS(root->left, totalSum);
        maxProductDFS(root->right, totalSum);
        maxAns = max(maxAns, root->val * 1LL * (totalSum - root->val));
    }
    int maxProduct(TreeNode* root) {
        int totalSum = dfs(root);
        maxProductDFS(root, totalSum);
        return maxAns % 1000000007;
    }
};