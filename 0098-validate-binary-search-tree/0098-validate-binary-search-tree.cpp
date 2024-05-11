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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        queue<pair<TreeNode*,pair<long long int,long long int>>> q;
        q.push({root,{LLONG_MIN,LLONG_MAX}});
        while(!q.empty()){
            auto node=q.front().first;
            long long int mini=q.front().second.first;
            long long int maxi=q.front().second.second;
            q.pop();
            if(node->left){
                if(node->left->val>=mini && node->left->val<=node->val){
                    q.push({node->left,{mini,node->val}});
                }else{
                    return false;
                }
            }
            if(node->right){
                if(node->right->val>=node->val && node->right->val<=maxi){
                    q.push({node->right,{node->val,maxi}});
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};