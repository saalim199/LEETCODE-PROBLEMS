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

    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> res;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int c=q.front().second;
            q.pop();
            if(c==res.size()) res.push_back(node->val);
            if(node->right) q.push({node->right,c+1});
            if(node->left) q.push({node->left,c+1});
        }
        return res;
    }
};