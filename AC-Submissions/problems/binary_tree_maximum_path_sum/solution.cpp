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
    int globalMax = 0, globalMin = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        globalMin = max(globalMin, root->val);
        int leftChild = max(0 ,dfs(root->left));
        int rightChild = max(0, dfs(root->right));
        int curMax = max(leftChild + rightChild + root->val, 0);
        globalMax = max(globalMax, curMax);
        curMax = max(leftChild + root->val, rightChild + root->val);
        
        return max(0,curMax);
    }
    int maxPathSum(TreeNode* root) {
        int a = dfs(root);
        if (globalMin < 0) return globalMin;
        return globalMax;
    }
};