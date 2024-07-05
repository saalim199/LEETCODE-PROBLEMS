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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* ptr=head->next;
        ListNode* prev=head;
        ListNode* nxt=ptr->next;
        int i=2;
        vector<int> res;
        while(nxt!=NULL){
            if((prev->val<ptr->val && ptr->val>nxt->val) || (prev->val>ptr->val && ptr->val<nxt->val)){
                res.push_back(i);
            }
            i++;
            prev=ptr;
            ptr=ptr->next;
            nxt=ptr->next;
        }
        if(res.size()<2) return {-1,-1};
        int maxi=res[res.size()-1]-res[0];
        int mini=INT_MAX;
        for(int i=0;i<res.size()-1;i++){
            mini=min(mini,res[i+1]-res[i]);
        }
        return {mini,maxi};
    }
};