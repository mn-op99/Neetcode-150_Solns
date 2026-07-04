class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m(nums.begin(), nums.end());
        return nums.size()!=m.size();
    }
};