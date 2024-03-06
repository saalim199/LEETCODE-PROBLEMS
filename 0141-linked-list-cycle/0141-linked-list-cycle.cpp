/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<int,int> mp;
        ListNode* ptr=head;
        ListNode* ptr2=head;
        while(ptr && ptr->next){
            ptr=ptr->next->next;
            ptr2=ptr2->next;
            if(ptr==ptr2) return true;
        }
        return false;
    }
};