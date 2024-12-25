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
private:
 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if (root == nullptr) {
            return ans; 
        }

        queue<TreeNode*> q; 
        q.push(root); 

        while (!q.empty()) {
            int size = q.size();
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop();
                level.push_back(node->val); 
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            ans.push_back(level); 
        }
        return ans; 
    }
public:
    vector<int> largestValues(TreeNode* root) {
    vector<vector<int>>levels=levelOrder(root);
    vector<int>ans;
    for(int i=0;i<levels.size();i++){
        int maxi=INT_MIN;
        for(int  j=0;j<levels[i].size();j++){
            maxi=max(maxi,levels[i][j]);
             cout<<levels[i][j]<<" ";
        }
       ans.push_back(maxi);
       cout<<endl;
    }
    return ans;
        
    }
};