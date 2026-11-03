class Solution {
private:
    void solve(int i, vector<int>& nums, int target,
               vector<int>& temp, vector<vector<int>>& res) {

        if(target == 0) {
            res.push_back(temp);
            return;
        }

        for(int j = i; j < nums.size(); j++) {

            if(j > i && nums[j] == nums[j-1])
                continue;

            if(nums[j] > target)
                break;

            temp.push_back(nums[j]);
            solve(j + 1, nums, target - nums[j], temp, res);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;

        solve(0, candidates, target, temp, res);

        return res;
    }
};