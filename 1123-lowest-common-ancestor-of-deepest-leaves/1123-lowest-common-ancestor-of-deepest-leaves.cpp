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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return root;
        vector<TreeNode*> deepest;
        queue<pair<TreeNode*,TreeNode*>> q;
        unordered_map<TreeNode*,TreeNode*> parent;
        q.push({root,NULL});
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> leaf;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                parent[node]=q.front().second;
                q.pop();
                leaf.push_back(node);
                if(node->left) q.push({node->left,node});
                if(node->right) q.push({node->right,node});
            }
            if(q.empty()) deepest=leaf;
        }
        if(deepest.size()==1) return deepest[0];
        while(deepest[0]!=deepest[deepest.size()-1]){
            deepest[0]=parent[deepest[0]];
            deepest[deepest.size()-1]=parent[deepest[deepest.size()-1]];
        }
        return deepest[0];
    }
};