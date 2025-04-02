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
    void traverse(TreeNode *root, vector<int> &pre){
        if(!root) return;
        traverse(root->left,pre);
        pre.push_back(root->val);
        traverse(root->right,pre);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        traverse(root,in);
        for(int i=1;i<in.size();i++){
            if(in[i]<=in[i-1]) return false;
        }
        return true;
    }
};