class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        mp[numbers[0]]=1;
        for(int i=1; i<numbers.size(); ++i){
            if(mp.find(target - numbers[i])!=mp.end()){
                return {mp[target - numbers[i]], i+1};
            }
            mp[numbers[i]]=i+1;
        }
        return {};
    }
};
