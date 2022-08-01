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
        ListNode* prev = nullptr;
        ListNode* pointer = head;
        ListNode* pointer2 = head;
        
        while (pointer2){
            pointer2 = pointer->next;
            pointer->next = prev;
            prev = pointer;
            if (!pointer2){
                break;
            }
            pointer = pointer2;
        }
        return pointer;
    }
};