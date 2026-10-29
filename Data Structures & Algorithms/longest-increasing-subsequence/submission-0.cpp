class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1; i<nums.size(); ++i){
            int j;
            for(j=res.size()-1; j>=0; --j){
                if(nums[i]<=res[j])
                    continue;
                else
                    break;
            }
            j++;
            if(j<res.size()){
                res[j] = nums[i];
            }
            else{
                res.push_back(nums[i]);
            }
        }
        return res.size();
    }
};
