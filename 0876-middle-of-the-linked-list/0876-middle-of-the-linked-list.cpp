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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            ptr=ptr->next;
        }
        return ptr;
        // int cnt=0;
        // while(ptr!=NULL){
        //     ptr=ptr->next;
        //     cnt++;
        // }
        // int mid;
        // if(cnt%2==0){
        //     mid=cnt/2+1;
        // }else{
        //     mid=(cnt+1)/2;
        // }
        // int i=1;
        // ptr=head;
        // while(i!=mid){
        //     ptr=ptr->next;
        //     i++;
        // }
        // return ptr;
    }
};