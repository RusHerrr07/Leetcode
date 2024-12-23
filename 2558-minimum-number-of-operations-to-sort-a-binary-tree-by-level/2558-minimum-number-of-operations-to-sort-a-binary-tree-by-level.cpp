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
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(level); 
        }
        return ans; 
    }

private:
    int cntSwap(vector<int>& arr) {
        int n = arr.size(), count = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            if (vec[i].first != arr[i]) {
                swap(vec[vec[i].second], vec[i]);
                i--;
                count++;
            }
        }
        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> levels = levelOrder(root);

        int cnt = 0;
        for (auto &vec : levels) {
            cnt += cntSwap(vec); 
        }
        return cnt;
    }
};
