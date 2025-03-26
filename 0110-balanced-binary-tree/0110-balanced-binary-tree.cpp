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
    int height(TreeNode *root, bool &f){
        if(!f) return 0;
        if(!root) return 0;
        int lh=height(root->left,f);
        int rh=height(root->right,f);
        if(abs(lh-rh)>1) {
            f=false;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool f=true;
        height(root,f);
        return f;
    }
};