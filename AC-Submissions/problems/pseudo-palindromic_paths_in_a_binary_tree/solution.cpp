class Solution {
public:
    int ans = 0;
    int num[10] = {};
    void dfs(TreeNode* root){
        if(!root)
            return;
        ++num[root->val];
        dfs(root->left);        
        dfs(root->right);
        // If at leaf node.
        if((!root->left) && (!root->right)){ 
            // Check if palindrome possible.
            int odd = 0;
            for(int i = 1; i < 10; ++i){
                if(num[i]&1)
                    ++odd;                
            }            
            if(odd<2)
                ++ans;            
        }
        //Remove the count as we have checked for that subtree.
        --num[root->val];        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};