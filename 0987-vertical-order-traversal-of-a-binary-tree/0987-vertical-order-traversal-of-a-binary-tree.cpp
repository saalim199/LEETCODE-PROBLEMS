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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> res;
        if(root==NULL) return {{}};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            mp[c][r].insert(node->val);
            if(node->left) q.push({node->left,{r+1,c-1}});
            if(node->right) q.push({node->right,{r+1,c+1}});
        }
        for(auto it:mp){
            vector<int> temp;
            for(auto a: it.second){
                // sort(a.second.begin(),a.second.end());
                temp.insert(temp.end(),a.second.begin(),a.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};