class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numSubsets = pow(2, nums.size());
        vector<vector<int>> res;
        for(int i=0; i<numSubsets; ++i){
            vector<int> temp;
            for(int j=0; j<31; ++j){
                if((i&(1<<j))>0)
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
