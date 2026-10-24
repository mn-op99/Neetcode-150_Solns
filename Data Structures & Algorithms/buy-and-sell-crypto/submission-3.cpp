class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxRight = prices[prices.size()-1];
        int res=0;
        for(int i=prices.size()-2; i>=0; --i){
            if(prices[i]<maxRight){
                res = max(res, maxRight - prices[i]);
            }
            maxRight = max(maxRight, prices[i]);
        }
        return res;
    }
};
