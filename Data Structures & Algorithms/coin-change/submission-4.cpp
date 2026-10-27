class Solution {
private:
    int solve(int i, vector<int> & coins, int amount, vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            return -1;
        }

        if(dp[i][amount]!=-2)
            return dp[i][amount];
        
        int take=-1, notTake=-1;
        if(amount>=coins[i]){
            int res = solve(i, coins, amount - coins[i], dp);
            if(res!=-1)
                take = 1 + res;
        }
        notTake = solve(i-1, coins, amount, dp);

        if(take==-1 && notTake==-1)
            return dp[i][amount] = -1;
        else if(take==-1)
            return dp[i][amount] = notTake;
        else if(notTake==-1)
            return dp[i][amount] = take;
        else
            return dp[i][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -2));
        return solve(n-1, coins, amount, dp);
    }
};
