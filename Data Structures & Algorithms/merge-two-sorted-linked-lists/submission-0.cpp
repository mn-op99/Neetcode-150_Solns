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
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        int val;
        if(temp1->val <= temp2->val){
            val = temp1->val;
            temp1 = temp1->next;
        }
        else{
            val = temp2->val;
            temp2 = temp2->next;
        }
        ListNode* res = new ListNode(val);
        ListNode* mover = res;
        while(temp1 || temp2){
            if(temp1 && temp2){
                int currVal;
                if(temp1->val <= temp2->val){
                    currVal = temp1->val;
                    temp1 = temp1->next;
                }
                else{
                    currVal = temp2->val;
                    temp2 = temp2->next;
                }
                ListNode* newNode = new ListNode(currVal);
                mover->next = newNode;
                mover = mover->next;
            }
            else if(temp1){
                ListNode* newNode = new ListNode(temp1->val);
                temp1 = temp1->next;
                mover->next = newNode;
                mover = mover->next;
            }
            else{
                ListNode* newNode = new ListNode(temp2->val);
                temp2 = temp2->next;
                mover->next = newNode;
                mover = mover->next;
            }
        }
        return res;
    }
};
