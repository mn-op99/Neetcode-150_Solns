class MinStack {
private:
    stack<int> st;
    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
        pq.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        mp[val]--;
        if(mp[val]==0)
            mp.erase(val);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int minVal = pq.top();
        while(mp.find(minVal)==mp.end()){
            pq.pop();
            minVal = pq.top();
        }
        return minVal;
    }
};
