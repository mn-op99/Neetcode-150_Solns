/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node *tail = &dummy;
        Node *temp = head;
        while(temp){
            tail->next = new Node(temp->val);
            tail=tail->next;
            temp=temp->next;
        }
        
        unordered_map<Node*, Node*> mp;
        temp = head;
        tail = dummy.next;
        while(temp){
            mp[temp] = tail;
            temp = temp->next;
            tail = tail->next;
        }

        temp = head;
        tail = dummy.next;
        while(temp){
            tail->random = mp[temp->random];
            temp = temp->next;
            tail = tail->next;
        }
        return dummy.next;
    }
};
