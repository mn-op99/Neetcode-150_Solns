class Solution {
private:
    int solve(int i, vector<int> &nums, vector<vector<int>> &dp, int sum, int totalSum, int target){
        if(i==nums.size())
            return target==sum;
        
        if(dp[i][sum+totalSum]!=-1)
            return dp[i][sum+totalSum];

        int takePos=0, takeNeg=0;
        takePos = solve(i+1, nums, dp, sum+nums[i], totalSum, target);
        takeNeg = solve(i+1, nums, dp, sum-nums[i], totalSum, target);

        return dp[i][sum+totalSum] = (takePos + takeNeg); 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int> (2*totalSum+2, -1));
        int sum=0;
        return solve(0, nums, dp, sum, totalSum, target);
    }
};
