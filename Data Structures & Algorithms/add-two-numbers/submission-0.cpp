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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode *mover = dummy;
        int carry=0, sum=0;
        while(l1!=NULL || l2!=NULL){
            sum=carry;
            if(l1){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2){
                sum += l2->val;
                l2=l2->next;
            }
            carry = sum>9?1:0;
            sum = sum%10;
            ListNode *newNode = new ListNode(sum);
            mover->next = newNode;
            mover = mover->next;
        }
        if(carry>0){
            ListNode *newNode = new ListNode(carry);
            mover->next = newNode;
        }
        return dummy->next;
    }
};
