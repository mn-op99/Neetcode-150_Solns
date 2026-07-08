class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> v;
        for(int i=0; i<nums.size(); ++i){
            unordered_map<int, int> m;
            for(int j=i+1; j<nums.size(); ++j){
                int rem = - nums[i] - nums[j];
                if(m.find(rem)!=m.end())
                    v.insert({nums[i], rem, nums[j]});
                m[nums[j]]=j;
            }
        }
        return vector<vector<int>> (v.begin(), v.end());
    }
};
