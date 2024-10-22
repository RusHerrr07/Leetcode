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
    vector<long long> bfs(TreeNode* root) {
        vector<long long> nums;
        if (root == nullptr) return nums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long levelSize = q.size();
            long long levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
                auto value = q.front();
                q.pop();
                levelSum += value->val;
                if (value->left != nullptr) q.push(value->left);
                if (value->right != nullptr) q.push(value->right);
            }
            nums.push_back(levelSum);
        }
        return nums;
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> nums = bfs(root);
        if (nums.size() < k) return -1;
        sort(nums.begin(), nums.end(), greater<long long>());
         // for (auto &i : nums) cout << i << " ";
        return nums[k - 1];
    }
};
