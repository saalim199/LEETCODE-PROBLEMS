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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode *ptr=head;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ListNode *prev=NULL;
        ptr=head;
        int k=c-n-1;
        if(k==-1) return head->next;
        while(k>0){
            ptr=ptr->next;
            k--;
        }
        ptr->next=ptr->next->next;
        return head;
    }
};