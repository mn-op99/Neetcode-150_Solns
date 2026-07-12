class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxValAtIdxI(prices.size());
        int n = prices.size();
        maxValAtIdxI[n-1] = prices[n-1];
        int res=0;
        for(int i=n-2; i>=0; --i){
            if(prices[i]>maxValAtIdxI[i+1]){
                maxValAtIdxI[i] = prices[i];
            }
            else{
                maxValAtIdxI[i] = maxValAtIdxI[i+1];
                res = max(res, maxValAtIdxI[i] - prices[i]);
            }
        }
        return res;
    }
};
