/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* ptr=head;
        Node* nhead=new Node(ptr->val);
        unordered_map<Node*,Node*> mp;
        mp[head]=nhead;
        while(ptr->next){
            nhead->next=new Node(ptr->next->val);
            ptr=ptr->next;
            nhead=nhead->next;
            mp[ptr]=nhead;
        }
        ptr=head;
        while(ptr){
            mp[ptr]->random=mp[ptr->random];
            ptr=ptr->next;
        }
        return mp[head];
    }
};