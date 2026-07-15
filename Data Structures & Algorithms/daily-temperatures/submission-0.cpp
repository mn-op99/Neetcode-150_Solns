class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size());
        for(int i=0; i<temperatures.size(); ++i){
            while(!st.empty() && st.top().first<temperatures[i]){
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        while(!st.empty()){
            res[st.top().second]=0;
            st.pop();
        }
        res[temperatures.size()-1]=0;
        return res;
    }
};
