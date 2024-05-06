/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void adjacent(TreeNode *root,unordered_map<TreeNode*,vector<TreeNode*>> &adj){
        if(root==NULL) return;
        if(root->left) {
            adj[root->left].push_back(root);
            adj[root].push_back(root->left);
        }
        if(root->right) {
            adj[root->right].push_back(root);
            adj[root].push_back(root->right);
        }
        adjacent(root->left,adj);
        adjacent(root->right,adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,vector<TreeNode*>> adj;
        queue<pair<TreeNode*,int>> q;
        unordered_map<TreeNode*,bool> vis;
        vector<int> ans;
        adjacent(root,adj);
        // for(auto it: adj){
        //     for(auto a: it.second){
        //         cout<<it.first->val<<" "<<a->val<<endl;
        //     }
        // }
        
        q.push({target,0});
        vis[target]=true;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int cnt=q.front().second;
            if((cnt)==k) break;
            q.pop();
            for(auto a:adj[node]){
                if(vis[a]==false){
                    vis[a]=true;
                    q.push({a,cnt+1});
                }
            }
        }
        while(!q.empty()){
            TreeNode* node=q.front().first;
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};