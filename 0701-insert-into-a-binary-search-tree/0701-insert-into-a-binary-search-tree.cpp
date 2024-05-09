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
    void insert(TreeNode* root, int val){
        TreeNode* prev=NULL;
        while(root){
            prev=root;
            if(root->val<val){
                root=root->right;
            }else{
                root=root->left;
            }
        }
        TreeNode* node=new TreeNode(val);
        if(prev->val<val){
            prev->right=node;
        }else{
            prev->left=node;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        insert(root,val);
        return root;
    }
};