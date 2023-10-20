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
        ListNode* curFast = head->next;
        while(curFast){
            if (curFast == cur){return true;}
            curFast = curFast->next;
            if (!curFast){
                return false;
            }else{
                curFast = curFast->next;
            }
            cur = cur->next;
        }
        return false;
    }
};