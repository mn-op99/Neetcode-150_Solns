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
        Node *temp = head;
        unordered_map<Node*, int> m;
        int idx=0;
        while(temp){
            m[temp]=idx++;
            temp=temp->next;
        }
        idx=0;
        vector<int> v1;
        temp=head;
        while(temp){
            if(temp->random==NULL)
                v1.push_back(-1);
            else{
                v1.push_back(m[temp->random]);
            }
            temp=temp->next;
        }
        Node dummy(0);
        Node *mover = &dummy;
        unordered_map<int, Node*> m1;
        idx=0;
        temp=head;
        while(temp){
            Node *newNode = new Node(temp->val);
            m1[idx++]=newNode;
            mover->next=newNode;
            mover=mover->next;
            temp=temp->next;
        }
        temp = (&dummy)->next;
        idx=0;
        while(temp){
            if(v1[idx]!=-1)
                temp->random = m1[v1[idx]];
            idx++;
            temp=temp->next;
        }
        return dummy.next;
    }
};
