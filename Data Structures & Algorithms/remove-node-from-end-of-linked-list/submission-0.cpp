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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lenLL = 0;
        ListNode *temp = head;
        while(temp){
            temp=temp->next;
            lenLL++;
        }
        int idx = lenLL - n;
        if(idx==0)
            return head->next;
        temp = head;
        while(--idx){
            temp = temp->next;
        }
        ListNode *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        return head;
    }
};
