class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int maxReach = 0;
        int end = 0;
        int ctSteps = 0;

        for(int i = 0; i < n-1; ++i) {

            maxReach = max(maxReach, i + nums[i]);

            if(i == end) {
                ctSteps++;
                end = maxReach;
            }
        }

        return ctSteps;
    }
};