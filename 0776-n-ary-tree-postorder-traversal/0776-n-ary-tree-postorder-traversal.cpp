class Solution {
public:
    void postorder(vector<int>& v, Node* root) {
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i < root->children.size(); i++) {
            postorder(v, root->children[i]);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        postorder(v, root);
        return v;
    }
};