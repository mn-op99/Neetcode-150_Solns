class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); ++i){
            char ch = tokens[i][0];
            if(tokens[i].size()>1){
                st.push(stoi(tokens[i]));
            }
            else if(ch>='0' && ch<='9'){
                st.push(stoi(tokens[i]));
            }
            else{
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                if(ch=='+')
                    st.push(val1+val2);
                else if(ch=='-')
                    st.push(val1-val2);
                else if(ch=='*')
                    st.push(val1*val2);
                else
                    st.push(val1/val2);
            }
        }
        return st.top();
    }
};
