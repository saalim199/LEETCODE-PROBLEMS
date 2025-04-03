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
    bool solve(TreeNode* root, int k, set<int> &s){
        if(!root) return false;
        if(s.find(k-root->val)!=s.end()){
            return true;
        }
        s.insert(root->val);
        return solve(root->left,k,s) || solve(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return solve(root,k,s);
    }
};