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
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int carry = 0;
        while(l1 || l2){
            int sum = 0;
            if(l1 && l2){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else{
                sum = l2->val + carry;
                l2 = l2->next;
            }

            if(sum>9){
                carry = 1;
                sum = sum % 10;
            }
            else
                carry=0;
                
            tail->next = new ListNode(sum);
            tail = tail->next;
        }
        if(carry>0){
            tail->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
