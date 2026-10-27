class Solution {
private:
    int solve(int i, int takenPrev, vector<int> &nums, vector<vector<int>> &dp){
        if(i==0){
            if(takenPrev)
                return 0;
            return nums[0];
        }
        
        if(dp[i][takenPrev]!=-1)
            return dp[i][takenPrev];
        
        int take = INT_MIN, notTake = INT_MIN;
        if(takenPrev)
            notTake = solve(i-1, 0, nums, dp);
        else{
            take = nums[i] + solve(i-1, 1, nums, dp);
            notTake = solve(i-1, 0, nums, dp);
        }
        return dp[i][takenPrev] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        return solve(n-1, 0, nums, dp);
    }
};
