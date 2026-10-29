class Solution {
private:
    bool solve(int i, vector<int> &nums, vector<vector<int>> &dp, int sum, int target){
        if(i==nums.size())
            return target==sum;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];

        bool take=false, notTake=false;
        if((target-sum)>=nums[i])
            take = solve(i+1, nums, dp, sum+nums[i], target);
        notTake = solve(i+1, nums, dp, sum, target);

        return dp[i][sum] = (take || notTake); 
    }
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i=0; i<nums.size(); ++i)
            target += nums[i];
        
        if((target&1)==1)
            return false;
        else
            target = target/2;
        
        vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
        int sum=0;
        return solve(0, nums, dp, sum, target);
    }
};
