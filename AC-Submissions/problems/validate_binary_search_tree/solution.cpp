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
    
    bool isValidBST(TreeNode* root) {
        bool okay = true;
        function<pair<int,int>(TreeNode*)> solve = [&] (TreeNode* cur) {
            if (okay == false) return make_pair(0, 0);
            if (cur -> left == NULL and cur -> right == NULL) {
                return make_pair(cur->val, cur->val);
            }
            
            pair<int, int> left, right, curmxmin;
            if (cur->left and cur->right) {
                left = solve(cur->left);
                right = solve(cur->right);
                if (left.second >= cur->val or right.first <= cur->val) {
                    okay = false;
                }
                return make_pair(left.first, right.second);
            }
            else if(cur->left) {
                left = solve(cur->left);
                if (left.second >= cur->val) okay = false;
                return make_pair(left.first, cur->val);
            }
            else {
                right = solve(cur->right);
                if (right.first <= cur->val) okay = false;
                return make_pair(cur->val, right.second);
            }
            
            return curmxmin;
        };   
        
        pair<int, int> dummy = solve(root);
        
        return okay;
    }
};