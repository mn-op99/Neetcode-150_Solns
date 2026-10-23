class Solution {
private:
    bool static comp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; ++i){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), comp);
        vector<int> res;
        int idx = v.size()-1;
        while(k--){
            res.push_back(v[idx].first);
            idx--;
        }
        return res;
    }
};
