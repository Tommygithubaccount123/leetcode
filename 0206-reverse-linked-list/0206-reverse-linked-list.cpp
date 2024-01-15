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
        if (!head){return nullptr;}
        
        ListNode* pointer = head;
        ListNode* prev = nullptr;
        ListNode* cur = pointer;
        
        while(pointer != nullptr){
            pointer = pointer->next;
            cur->next = prev;
            prev = cur;
            cur = pointer;
        }
        return prev;
    }
};