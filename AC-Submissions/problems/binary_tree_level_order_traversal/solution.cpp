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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> v[2001]; int mx = -1;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* poot, int level){
            if(poot == NULL)return;
            mx = max(mx, level);
            v[level].push_back(poot->val);
            if(poot->left != NULL){
                dfs(poot->left, level + 1);
            }
            if(poot->right != NULL){
                dfs(poot->right, level + 1);
            }
        };
        dfs(root, 0);
        vector<vector<int>> ans;
        for(int i = 0; i <= mx; i++){
            vector<int> vs;
            for(auto it: v[i])vs.push_back(it);
            ans.push_back(vs);
        }
        return ans;
    }
};