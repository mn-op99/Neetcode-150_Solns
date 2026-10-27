class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node *next = NULL;
        Node *prev = NULL;

        Node(int key, int data){
            this->key = key;
            this->val = data;
            next = NULL;
            prev = NULL;
        }
    };
    unordered_map<int, Node*> mp;
    int size, capacity;
    Node *head, *tail;

public:
    LRUCache(int capacity) {
        //Implementing queue using LL
        this->capacity = capacity;
        this->size=0; //Initially
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *reqNode = mp[key];
            if(reqNode==head && reqNode->next!=NULL)
                head = head->next;
            if(reqNode->next!=NULL){
                if(reqNode->prev!=NULL)
                    reqNode->prev->next = reqNode->next;
                if(reqNode->next!=NULL)
                    reqNode->next->prev = reqNode->prev;
                tail->next = reqNode;
                reqNode->next = NULL;
                reqNode->prev = tail;
                tail = tail->next;    
            }
            return reqNode->val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;

        if(head==NULL){
            Node *newNode = new Node(key, value);
            mp[key] = newNode;
            head = newNode;
            tail = newNode;

            size++;
            if(size>capacity){
                Node *deleteNode = head;
                mp.erase(head->key);

                head = head->next;
                if(head)
                    head->prev=NULL;
                else
                    tail = NULL;
                
                delete deleteNode;
                size--;
            }
        }
        else{
            if(mp.find(key)!=mp.end()){
                Node *reqNode = mp[key];
                reqNode->val = value;

                if(reqNode==head && reqNode->next!=NULL)
                    head = head->next;
                
                if(reqNode->next!=NULL){
                    if(reqNode->prev!=NULL)
                        reqNode->prev->next = reqNode->next;
                    if(reqNode->next!=NULL)
                        reqNode->next->prev = reqNode->prev;
                    tail->next = reqNode;
                    reqNode->next = NULL;
                    reqNode->prev = tail;
                    tail = tail->next;
                }
            }
            else{
                Node *newNode = new Node(key, value);
                mp[key] = newNode;
                tail->next = newNode;
                newNode->prev = tail;
                tail = tail->next;

                size++;
                if(size>capacity){
                    Node *deleteNode = head;
                    mp.erase(head->key);

                    head = head->next;
                    if(head)
                        head->prev=NULL;
                    else
                        tail = NULL;
                    
                    delete deleteNode;
                    size--;
                }
            }
        }
        
    }
};
