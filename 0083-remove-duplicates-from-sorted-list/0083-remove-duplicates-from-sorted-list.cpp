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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* ptr=head;
        while(ptr!=NULL){
            prev=ptr;
            ptr=ptr->next;
            while(ptr && ptr->val==prev->val){
                ptr=ptr->next;
            }
            prev->next=ptr;
        }
        return head;
    }
};