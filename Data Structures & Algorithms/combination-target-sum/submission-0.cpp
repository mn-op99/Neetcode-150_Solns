class Solution {
private:
    void solve(int i, vector<int> &nums, int target, vector<int> &temp, vector<vector<int>> &res){
        if(i==nums.size())
            return;
        if(target==0){
            res.push_back(temp);
            return;
        }

        solve(i+1, nums, target, temp, res);
        if(target>=nums[i]){
            temp.push_back(nums[i]);
            solve(i, nums, target-nums[i], temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, target, temp, res);
        return res;
    }
};
