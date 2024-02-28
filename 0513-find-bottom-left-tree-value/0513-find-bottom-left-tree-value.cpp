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
    void solve(TreeNode* p,int currHeight,int &height,int &ans){
        if(p==NULL) return;
        if(currHeight>height){
            height=currHeight;
            ans=p->val;
        }
        solve(p->left,currHeight+1,height,ans);
        solve(p->right,currHeight+1,height,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=-1;
        int height=0;
        int curr=1;
        solve(root,1,height,ans);
        return ans;
    }
};