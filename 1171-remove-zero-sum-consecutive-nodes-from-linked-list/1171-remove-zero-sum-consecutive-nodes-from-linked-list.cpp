/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode *ptr=head;
        while(ptr!=NULL){
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        vector<int> preSum(v.size()+1,0);
        preSum[0]=0;
        for(int i=0;i<v.size();i++){
            preSum[i+1]=preSum[i]+v[i];
        }
        vector<int> res;
        for(int i=0;i<preSum.size()-1;i++){
            res.push_back(v[i]);
            // cout<<"i "<<i<<endl;
            for(int j=preSum.size()-1;j>i;j--){
                // cout<<"j "<<j;
                if(preSum[i]==preSum[j]){
                    res.pop_back();
                    i=j-1;
                    break;
                }
            }
            // cout<<endl;
        }
        if(res.size()==0) return NULL;
        for(auto it:res) cout<<it<<" ";
        ListNode *headn=new ListNode();
        headn->val=res[0];
        ptr=headn;
        int i=1;
        while(i<res.size()){
            ListNode *t=new ListNode();
            t->val=res[i++];
            ptr->next=t;
            ptr=ptr->next;
        }
        return headn;
    }
};