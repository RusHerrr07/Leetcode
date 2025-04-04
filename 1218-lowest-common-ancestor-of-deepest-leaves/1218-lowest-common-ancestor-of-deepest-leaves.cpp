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
     pair<TreeNode*, int> solve(TreeNode* root, int depth){
        if(root==NULL) return {root, depth+1};

        pair<TreeNode*, int> l = solve(root->left, depth+1);
        pair<TreeNode*, int> r = solve(root->right, depth+1);

        if(l.second<r.second) return r;
        else if(l.second>r.second) return l;
        return {root, l.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root, 0).first;
        
    }
};