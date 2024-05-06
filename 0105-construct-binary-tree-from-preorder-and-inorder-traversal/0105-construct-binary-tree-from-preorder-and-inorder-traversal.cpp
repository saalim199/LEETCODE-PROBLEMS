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
    TreeNode* build(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd, unordered_map<int,int> &inMap){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode *root=new TreeNode(pre[preStart]);
        int inRoot=inMap[root->val];
        int x=inRoot-inStart;
        root->left=build(pre,preStart+1,preStart+x,in,inStart,inRoot-1,inMap);
        root->right=build(pre,preStart+x+1,preEnd,in,inRoot+1,inEnd,inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int> inMap;
        for(int i=0;i<in.size();i++){
            inMap[in[i]]=i;
        }
        return build(pre,0,pre.size()-1,in,0,in.size()-1,inMap);
    }
};