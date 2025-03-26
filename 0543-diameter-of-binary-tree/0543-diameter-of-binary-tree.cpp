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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void helper(TreeNode* root, int &m){
        if(!root) return;
        helper(root->left,m);
        helper(root->right,m);
        int l=height(root->left);
        int r=height(root->right);
        m=max(m,l+r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int m=0;
        helper(root,m);
        return m;
    }
};