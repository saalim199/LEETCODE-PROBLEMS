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
    ListNode* solve(ListNode *h1,ListNode *h2){
        if(!h1){
            return h2;
        }
        else if(!h2){
            return h1;
        }
        if(h1->val > h2->val){
            ListNode *temp=h2->next;
            h2->next=NULL;
            h2->next=solve(h1,temp);
            return h2;
        }else{
            ListNode *temp=h1->next;
            h1->next=NULL;
            h1->next=solve(temp,h2);
            return h1;
        }
    }
    ListNode* merge(vector<ListNode*>& lists,int start,int end){
        if(start>end) return NULL;
        if(start==end) return lists[end];
        int mid=(start+end)/2;
        ListNode *l1=merge(lists,start,mid);
        ListNode *l2=merge(lists,mid+1,end);
        return solve(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        // ListNode *head=solve(lists[0],lists[1]);
        // for(int i=2;i<lists.size();i++)
        //     head=solve(head,lists[i]);
        // return head;
        return merge(lists,0,lists.size()-1);
    }

};