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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long ans=0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long mini=q.front().second;
            // cout<<"MINI "<<mini<<endl;
            long long maxi=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                long long num=q.front().second;
                q.pop();
                num-=mini;
                // cout<<num<<" ";
                if(i==n-1) maxi=num;
                if(node->left) q.push({node->left,(2*num)+1});
                if(node->right) q.push({node->right,(2*num)+2});
            }
            // cout<<endl;
            ans=max(ans,maxi+1);
        }
        return ans;
    }
};