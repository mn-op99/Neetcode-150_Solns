class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x: nums){
            if(m.find(x)==m.end())
                m[x]=1;
            else
                return true;
        }
        return false;
    }
};