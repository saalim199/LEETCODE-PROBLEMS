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
    TreeNode* construct(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int> &mp){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int index=mp[root->val];
        int shift=index-is;
        root->left=construct(preorder,ps+1,ps+shift,inorder,is,index-1,mp);
        root->right=construct(preorder,ps+shift+1,pe,inorder,index+1,ie,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};