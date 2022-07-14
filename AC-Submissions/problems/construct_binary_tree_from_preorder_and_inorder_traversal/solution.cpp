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
    int cntr = -1;
    unordered_map<int, int> hashMap;
    TreeNode* recur(int l, int r, vector<int>& preorder, vector<int>& inorder){
        //cout << l <<" " << r <<" " << cntr << endl;
        if(r < l)return NULL;
        TreeNode *cur = new TreeNode();
        cntr++;
        if(cntr >= preorder.size())return NULL;
        cur->val = preorder[cntr];
        int a = hashMap[cur->val];
        cur->left = recur(l, a - 1, preorder, inorder);
        cur->right = recur(a + 1, r, preorder, inorder);
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++){
            hashMap[inorder[i]] = i;
        }
        
        TreeNode* root = recur(0, preorder.size() - 1, preorder, inorder);
        return root;
    }
};