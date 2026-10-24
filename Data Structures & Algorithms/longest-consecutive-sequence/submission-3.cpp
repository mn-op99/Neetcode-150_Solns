class Solution {
    // int solve(int i, vector<int> &nums, vector<int> &dp){

    // }
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(), nums.end());
        int ans=1;
        int ct=1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]==nums[i-1])
                continue;
            if((nums[i]-nums[i-1])==1){
                ct++;
                ans = max(ct, ans);
            }
            else{
                ct=1;
            }
        }
        return ans;
    }
};
