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
    TreeNode* solve(string& traversal, int& i, int level) {
        if (i >= traversal.size()) {

            return nullptr; 
        }

        int cnt = 0;
        while (i < traversal.size() && traversal[i] == '-') {
            cnt++;
            i++;
        }

        if (cnt != level) {
            i -= cnt;
            return nullptr;
        }

        int num =0; 

        while (i < traversal.size() && traversal[i] != '-') {
            num = (num * 10) + (traversal[i] - '0'); 
            i++;
        }

        TreeNode* root =
            new TreeNode(num);

        root->left = solve(traversal,i,level + 1);
        root->right = solve(traversal,i,level + 1); 

        return root; 
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        return solve(traversal, i, 0);
    }
};