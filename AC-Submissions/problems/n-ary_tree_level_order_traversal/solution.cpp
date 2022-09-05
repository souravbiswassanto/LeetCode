/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levelOrder;
        if (root == NULL) return levelOrder;
        queue<pair<Node*, int>> Q;
        vector<int> v; v.push_back(root->val);
        Q.push({root, 0});
        int d = -1, depth;
        while(!Q.empty()) {
            Node* Front = Q.front().first;
            depth = Q.front().second;
            Q.pop(); 
            if (d + 1 == depth) {
                levelOrder.push_back(v);
                d = depth;
                v.clear();
            }
            for (int i = 0; i < Front->children.size(); ++i) {
                Q.push({Front->children[i], depth + 1});
                v.push_back(Front->children[i]->val);
            }
            
        }
        if (d + 1 == depth) levelOrder.push_back(v);
        return levelOrder;
    }
    
};