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
        vector<ListNode*> storage;
        while(head){
            storage.push_back(head);
            head = head->next;
        }
        
        int l = 0;
        int r = storage.size() - 1;
        while (l < r){
            if (storage[l]->val == storage[r]->val){
                l++;
                r--;
                continue;
            }
            return false; 
        }
        return true;
    }
};