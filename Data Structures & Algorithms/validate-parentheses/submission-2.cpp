class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        for(int i=0; i<s.size(); ++i){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else{
                if(st.empty() || st.top()!=m[ch])
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
