class Solution {
public:
    static bool compare(pair<int, int> &x, pair<int, int> &y){
        return x.second < y.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; ++i){
            m[nums[i]]++;
        }

        vector<pair<int, int>> v;
        for(auto it=m.begin(); it!=m.end(); ++it){
            v.push_back({(*it).first, (*it).second});
        }
        sort(v.begin(), v.end(), compare);
        vector<int> res;
        int i=v.size()-1;
        while(k--){
            res.push_back(v[i--].first);
        }
        return res;
    }
};
