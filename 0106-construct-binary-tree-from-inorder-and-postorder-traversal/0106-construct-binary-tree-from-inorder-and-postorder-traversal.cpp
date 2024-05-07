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
private:
    TreeNode* buildTree(vector<int>& inorder,int sin,int ein,vector<int>& postorder,
    int sp,int ep,unordered_map<int,int> &inMap) {
        if(sin>ein || sp>ep) return NULL;
        TreeNode* root=new TreeNode(postorder[ep]);
        int inRoot=inMap[root->val];
        int shift=inRoot-sin;
        root->left=buildTree(inorder,sin,sin+shift-1,postorder,sp,sp+shift-1,inMap);
        root->right=buildTree(inorder,sin+shift+1,ein,postorder,sp+shift,ep-1,inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
    }
};