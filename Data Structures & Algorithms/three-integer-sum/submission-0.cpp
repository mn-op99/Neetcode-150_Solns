class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> v;
        for(int i=0; i<nums.size(); ++i){
            int val = nums[i];
            unordered_map<int, int> m;
            for(int j=i+1; j<nums.size(); ++j){
                int rem = 0 - val - nums[j];
                if(m.find(rem)!=m.end())
                    v.insert({val, rem, nums[j]});
                m[nums[j]]=j;
            }
        }
        vector<vector<int>> res(v.begin(), v.end());
        return res;
    }
};
