class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        set<vector<int>> st;
        mp[nums[0]]=0;
        for(int i=1; i<nums.size(); ++i){
            int secondVal = nums[i];
            for(int j=i+1; j<nums.size(); ++j){
                int thirdVal = nums[j];
                int firstVal = -secondVal -thirdVal;
                if(mp.find(firstVal)!=mp.end()){
                    vector<int> temp = {firstVal, secondVal, thirdVal};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
            mp[nums[i]]=i;
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
