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
        ListNode* cur = head;
        if(!cur){return false;}
        ListNode* curFast = head;
        
        while(curFast && curFast->next){
            curFast = curFast->next->next;
            cur = cur->next;
            if (curFast == cur){return true;}
        }
        return false;
    }
};