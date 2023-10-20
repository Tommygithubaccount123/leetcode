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
        ListNode* pointer = head;
        ListNode* cur = pointer;
        ListNode* prev = nullptr;
        
        while(pointer){
            cur = pointer;
            pointer = pointer->next;
            cur->next = prev;
            prev = cur;
        }
        return cur;
    }
};