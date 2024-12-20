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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=0;
        dfs(root,root->left,root->right,level);
        return root;
    }
    void dfs(TreeNode* root, TreeNode* leftt, TreeNode* rightt, int level){
        if(leftt==NULL && rightt==NULL) return;
        if(!(level &1)){
            swap(leftt->val,rightt->val);
        }
        dfs(root,leftt->left,rightt->right,level+1);
        dfs(root,leftt->right,rightt->left,level+1);
    }
};