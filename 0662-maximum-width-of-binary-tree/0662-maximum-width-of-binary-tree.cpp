/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if (root == NULL)
            return 0;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int size=q.size();
            long long mini = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long m = q.front().second - mini;
                q.pop();
                if (i == 0)
                    first = m;
                if (i == size - 1)
                    last = m;
                if (node->left)
                    q.push({node->left, (2 * m) + 1});
                if (node->right)
                    q.push({node->right, (2 * m )+ 2});
            }
            ans = max(ans, (last - first) + 1);
        }
        return ans;
    }
};