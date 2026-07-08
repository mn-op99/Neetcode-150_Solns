class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        vector<vector<int>> v(n+1); 
        for(auto it = m.begin(); it!=m.end(); ++it){
            v[it->second].push_back(it->first);
        }

        vector<int> res;
        for(int i=n; i>=1; --i){
            for(int j=0; j<v[i].size(); ++j){
                res.push_back(v[i][j]);
                --k;
                if(!k)
                    return res;
            }
        }
        return res;
    }
};
