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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2){return nullptr;}
        if (!list1){return list2;}
        if (!list2){return list1;}
        
        ListNode* head = nullptr;
        if (list1->val >= list2->val){
            head = list2;
            list2 = list2->next;
        } else {
            head = list1;
            list1 = list1->next;
        }
        ListNode* pointer = head;
        
        while (list1 && list2){
            if (list1->val >= list2->val){
                pointer->next = list2;
                list2 = list2->next;
                pointer = pointer->next;
            } else {
                pointer->next = list1;
                list1 = list1->next;
                pointer = pointer->next;
            }
        }
        
        if (list1){
            pointer->next = list1;
        }
        
        if (list2){
            pointer->next = list2;
        }
        return head;
    }
};