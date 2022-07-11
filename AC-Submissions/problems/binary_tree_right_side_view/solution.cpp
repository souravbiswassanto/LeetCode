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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        TreeNode* vat = new TreeNode(0, NULL, root);
        
        int level[200];
        for(int i = 0; i < 200; i++)level[i] = -200;
        
        function<void(TreeNode*, int)> recur =[&](TreeNode* poot, int lv){
            if(poot == NULL)return;
            if(poot != NULL and level[lv] == -200){
                level[lv] = poot->val;
            }
            if(poot->right != NULL)recur(poot->right, lv + 1);
            if(poot->left != NULL)recur(poot->left, lv + 1);
        };
        recur(root, 0);
        int cnt = 0;
        while(level[cnt] != -200){
            v.push_back(level[cnt++]);
        }
        return v;
    }
};