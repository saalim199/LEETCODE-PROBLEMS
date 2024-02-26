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
    // void traverse(TreeNode* k,vector<int> &v){
    //     if(k==NULL) {
    //         v.push_back(-1);
    //         return;
    //         }
    //     traverse(k->left,v);
    //     cout<<k->val<<" ";
    //     v.push_back(k->val);
    //     traverse(k->right,v);
    // }
    bool traverse(TreeNode *p,TreeNode *q){
        if(p==NULL && q==NULL) return true;
        else if(p==NULL && q!=NULL) return false;
        else if(p!=NULL && q==NULL) return false;
        return p->val==q->val && traverse(p->left,q->left) && traverse(p->right,q->right);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // vector<int> v1,v2;
        // traverse(p,v1);
        // traverse(q,v2);
        // if(v1.size()!=v2.size()) return 0;
        // for(int i=0;i<v1.size();i++){
        //     // cout<<v1[i]<<" "<<v2[i]<<endl;
        //     if(v1[i]!=v2[i]) return 0;
        // }
        // return 1;
        return traverse(p,q);
    }
};