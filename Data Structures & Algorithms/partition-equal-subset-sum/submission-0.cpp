class Solution {
private:
    bool solve(int i, vector<int> &nums, vector<vector<int>> &dp, int target){
        if(i==nums.size())
            return target==0;
        
        if(dp[i][target]!=-1)
            return dp[i][target];

        bool take=false, notTake=false;
        if(target>=nums[i])
            take = solve(i+1, nums, dp, target-nums[i]);
        notTake = solve(i+1, nums, dp, target);

        return dp[i][target] = (take || notTake); 
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
        return solve(0, nums, dp, target);
    }
};
