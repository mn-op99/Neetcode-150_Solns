class Solution {
private:
    int solve(int i, int coin, vector<int> &prices, vector<vector<int>> &dp){
        if(i>=prices.size())
            return 0;
        
        if(dp[i][coin+1]!=-1)
            return dp[i][coin+1];
        
        if(coin==-1){
            int take = solve(i+1, prices[i], prices, dp);
            int notTake = solve(i+1, coin, prices, dp);
            return dp[i][coin+1] = max(take, notTake);
        }else{
            int take=0, notTake=0;
            if(prices[i]>=coin)
                take = prices[i] - coin + solve(i+2, -1, prices, dp);
            notTake = solve(i+1, coin, prices, dp);
            return dp[i][coin+1] = max(take, notTake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int maxCoin = 1;
        for(auto it: prices)
            maxCoin = max(maxCoin, it);
        
        vector<vector<int>> dp(prices.size(), vector<int>(maxCoin+2, -1));
        return solve(0, -1, prices, dp);
        
    }
};
