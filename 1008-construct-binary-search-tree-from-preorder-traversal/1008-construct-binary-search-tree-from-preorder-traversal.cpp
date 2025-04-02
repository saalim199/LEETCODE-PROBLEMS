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
    void construct(TreeNode* &root, vector<int> &preorder, vector<int> &inorder,
    unordered_map<int,int> &inMap, int inStart, int inEnd, int preStart, int preEnd){
        if(inStart>inEnd || preStart>preEnd) return;
        TreeNode *node = new TreeNode();
        int ele=preorder[preStart];           //1 3 2
        int inIdx=inMap[ele];          //           s e
        int n=inIdx-inStart; //1              //1 2 3
        node->val=ele;                      //      s e
        root=node;
        construct(root->left,preorder,inorder,inMap,inStart,inIdx-1,preStart+1,preStart+n);
        construct(root->right,preorder,inorder,inMap,inIdx+1,inEnd,preStart+n+1,preEnd);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        TreeNode* root=new TreeNode();
        construct(root,preorder,inorder,inMap,0,n-1,0,n-1);
        return root;
    }
};