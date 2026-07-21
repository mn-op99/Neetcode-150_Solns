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
        ListNode* temp = head;
        for(int i=1; i<n; ++i){
            temp = temp->next;
        }

        if(temp->next==NULL){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode *temp1 = head, *prev = head;
        while(temp->next){
            temp=temp->next;
            prev=temp1;
            temp1=temp1->next;
        }
        
        prev->next = temp1->next;
        delete temp1;
        return head;
    }
};
