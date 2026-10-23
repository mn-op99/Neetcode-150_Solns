class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto v: nums){
            if(st.find(v)!=st.end())
                return true;
            st.insert(v);
        }
    return false;
    }
};