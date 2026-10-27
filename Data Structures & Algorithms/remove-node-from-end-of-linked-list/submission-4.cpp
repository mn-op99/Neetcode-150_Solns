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
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode*temp = head;
        if(n==1){
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            ListNode *deleteNode = temp->next;
            temp->next = NULL;
            delete deleteNode;
        }
        else{
            int len = 0;
            while(temp!=NULL){
                len++;
                temp=temp->next;
            }
            int idx = len - n - 1;
            if(len==n){
                ListNode *deleteNode = head;
                head=head->next;
                delete deleteNode;
                return head;
            }
            else{
                temp = head;
                while(idx--){
                    temp = temp->next;
                }
                ListNode *deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode;
            }
        }
        return head;
    }
};
