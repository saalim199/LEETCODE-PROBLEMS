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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;

        }
        return prev;
        // int i=0;
        // ListNode* ptr=head;
        // int j=0;
        // while(ptr!=NULL){
        //     ptr=ptr->next;
        //     j++;
        // }
        // ListNode* ptr1=head;
        // while(i<j){
        //     int k=1;
        //     ptr=head;
        //     while(k!=j){
        //         ptr=ptr->next;
        //         k++;
        //     }
        //     int temp=ptr1->val;
        //     ptr1->val=ptr->val;
        //     ptr->val=temp;
        //     i++;
        //     j--;
        //     ptr1=ptr1->next;
        // }
        return head;
    }
};