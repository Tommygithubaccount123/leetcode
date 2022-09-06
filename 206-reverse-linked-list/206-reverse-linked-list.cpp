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
        if (!head->next){return head;}
        
        ListNode* pointer = head;
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (pointer && pointer->next){
            pointer = pointer->next;
            current->next = prev;
            prev = current;
            current = pointer;
        }
        current->next = prev;
        return current;
    }
};