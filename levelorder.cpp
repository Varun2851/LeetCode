class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans; // Return empty result for null root
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> res;

            for (int i = 0; i < size; i++) {
                TreeNode* X = q.front();
                q.pop();

                if (X != nullptr) {
                    res.push_back(X->val);

                    if (X->left != nullptr) {
                        q.push(X->left);
                    }

                    if (X->right != nullptr) {
                        q.push(X->right);
                    }
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};