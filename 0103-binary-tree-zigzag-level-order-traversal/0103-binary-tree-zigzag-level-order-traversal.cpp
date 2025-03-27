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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        bool toReverse=false;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.mepty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(root->left);
                if(node->right) q.push(root->right);
            }
            if(toReverse){
                reverse(level.begin(),level.end());
                toReverse=!toReverse;
            }
            ans.push_back(level);
        }
        return ans;
    }
};