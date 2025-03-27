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
    int helper(TreeNode* root, int &total){
        if(!root) return 0;
        int left=helper(root->left,total);
        int right=helper(root->right,total);
        int maxi=max(root->val,max(left+root->val,right+root->val));
        total=max(total,maxi);
        total=max(total,left+right+root->val);
        return maxi;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int total=root->val;
        helper(root,total);
        return total;
    }
};