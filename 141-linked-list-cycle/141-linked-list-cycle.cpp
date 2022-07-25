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
        unordered_map<ListNode*,int> storage;
        while(head){
            if (storage.find(head)==storage.end()){
                storage[head] = 0;
            } else {
                return true;
            }
            head = head->next;
        }
        
        return false;
    }
};