class Solution {
private:
    int solve(int i, int n, vector<int> &cost, vector<int> &dp){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i] = cost[i] + min(solve(i+1, n, cost, dp), solve(i+2, n, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size()+1, -1);
        int val = solve(0, n, cost, dp);
        return min(dp[0], dp[1]);
    }
};
