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
    bool helper(TreeNode* root,int ts,int s){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return (s+root->val)==ts;
        s+=root->val;
        bool left=helper(root->left,ts,s);
        bool right=helper(root->right,ts,s);
        return (left || right);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int s=0;
        return helper(root,targetSum,s);
    }
};