class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0);

        if(sumGas<sumCost)
            return -1;
        
        vector<int> diff(gas.size(), 0);
        for(int i=0; i<gas.size(); ++i){
            diff[i] = gas[i]-cost[i];
        }

        int start=0;
        int tank=0;
        for(int i=0; i<gas.size(); ++i){
            tank+=diff[i];
            if(tank<0){
                tank=0;
                start=(i+1);
            }
        }
        return start;
    }
};
