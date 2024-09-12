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
    int heights(TreeNode* root){
   if(root==nullptr)return 0;
   int lh=heights(root->left);
   int rh=heights(root->right);
   return 1+max(lh,rh);
   }
   int helper(TreeNode* root, int &maxi){
    if(root==nullptr)return 0;
        int lefttree=heights(root->left);
        int righttree=heights(root->right);
        maxi=max(maxi,lefttree+righttree);
        helper(root->left,maxi);
        helper(root->right,maxi);
        return maxi;
   }
    int diameterOfBinaryTree(TreeNode* root) {
        int m=0;
        return helper(root,m);
    }
};