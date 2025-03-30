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
    void makeTree(TreeNode* &root, vector<int>& preorder, vector<int>& inorder){
        TreeNode* node=new TreeNode();
        node->val=preorder[0];
        root=node;
        // cout<<root->val<<" ";
        if(preorder.size()>1){
            // int found=0;
            int cnt=0;
            for(int i=0;i<inorder.size();i++){
                if(inorder[i]==preorder[0]){
                    // found=i;
                    break;
                }
                else cnt++;
            }
            // vector<int> newPre = ;
            // vector<int> newIn = ;
            int n=preorder.size();
            cnt++;
            vector<int> leftPre(preorder.begin()+1,preorder.begin()+cnt);
            vector<int> leftIn(inorder.begin(),inorder.begin()+cnt);
            vector<int> rightPre(preorder.begin()+cnt,preorder.end());
            vector<int> rightIn(inorder.begin()+cnt,inorder.end());
            makeTree(root->left,leftPre,leftIn);
            makeTree(root->right,rightPre,rightIn);
        } 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* node=new TreeNode();
        makeTree(node,preorder,inorder);
        return node; 
    }
};