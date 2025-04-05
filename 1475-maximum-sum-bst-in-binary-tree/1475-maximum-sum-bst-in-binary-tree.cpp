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
 class Node{
    public:
    int min;
    int max;
    int sum;
    bool isBST;
    Node(int min,int max,int sum,bool isBST){
        this->min=min;
        this->max=max;
        this->sum=sum;
        this->isBST=isBST;
    }
 };
class Solution {
public:
    Node solve(TreeNode* root, int &res){
        if(!root) return Node(INT_MAX,INT_MIN,0,true);
        Node left=solve(root->left,res);
        Node right=solve(root->right,res);
        int sum=root->val;
        if(left.isBST && right.isBST){
            if(root->val>left.max && root->val<right.min){
                sum+=left.sum+right.sum;
                res=max(res,sum);
                return Node(min(root->val, left.min), max(root->val,right.max),sum,true);
            }
        }
        return Node(INT_MAX,INT_MIN,max(left.sum,right.sum),false);
    }
    int maxSumBST(TreeNode* root) {
        int total=0;
        solve(root,total);
        return total;
    }
};