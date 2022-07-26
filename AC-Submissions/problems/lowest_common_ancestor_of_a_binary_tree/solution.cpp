/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* answer; 
        bool isFoundBoth = false;
        function<bool(TreeNode*)> dfs = [&](TreeNode* cur){
            if (cur == NULL) return false;
            bool isFoundP = false;
            bool isFoundQ = false;
            
            isFoundP = dfs(cur->left);
            isFoundQ = dfs(cur->right);
    
            if (isFoundP and isFoundQ) {
                if (isFoundBoth == false) {
                    isFoundBoth = true;
                    answer = cur;
                }
            }
            if((isFoundP | isFoundQ) and (cur == p or cur == q)){
                if (isFoundBoth == false) {
                    isFoundBoth = true;
                    answer = cur;
                }
            }
            if(p == cur or q == cur) return true;
            return bool(isFoundP | isFoundQ);
            
        };
        bool dummy = dfs(root);
        return answer;
    }
};