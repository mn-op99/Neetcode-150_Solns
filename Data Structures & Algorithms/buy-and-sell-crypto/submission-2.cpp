class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal=prices[0];
        int res=0;
        for(int i=1; i<prices.size(); ++i){
            minVal = min(minVal, prices[i]);
            res = max(res, prices[i] - minVal);
        }
        return res;
    }
};
