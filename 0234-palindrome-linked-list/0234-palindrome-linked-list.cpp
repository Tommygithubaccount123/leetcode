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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* tail = reverse(slow);
        while (tail && head){
            if (tail->val != head->val){
                return false;
            }
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        if (!head){return nullptr;}
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* pointer = head;
        while (pointer){
            pointer = pointer->next;
            cur->next = prev;
            prev = cur;
            cur = pointer;
        }
        return prev;
    }
};