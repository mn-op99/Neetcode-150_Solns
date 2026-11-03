class Solution {
private:
    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, set<vector<int>> &st){
        if(i==nums.size()){
            if(st.find(temp)==st.end()){
                res.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        solve(i+1, nums, temp, res, st);
        temp.push_back(nums[i]);
        solve(i+1, nums, temp, res, st);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> st;
        solve(0, nums, temp, res, st);
        return res;
    }
};
