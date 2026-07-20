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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return false;
        ListNode* slowPtr = head->next;
        ListNode* fastPtr = head->next->next;
        while(fastPtr!=NULL){
            if(slowPtr==fastPtr)
                return true;
            slowPtr = slowPtr->next;
            if(fastPtr->next==NULL)
                return false;
            fastPtr = fastPtr->next->next;
        }
        return false;
    }
};
