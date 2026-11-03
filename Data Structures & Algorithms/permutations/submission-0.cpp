class Solution {
private:
    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }

        for(int j=i; j<nums.size(); ++j){
            swap(nums[i], nums[j]);
            temp.push_back(nums[i]);
            solve(i+1, nums, temp, res);
            swap(nums[i], nums[j]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, temp, res);
        return res;
    }
};
