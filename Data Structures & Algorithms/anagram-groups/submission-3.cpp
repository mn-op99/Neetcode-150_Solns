class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> v;
        for(int i=0; i<strs.size(); ++i){
            v.push_back({strs[i], i});
            sort(v[i].first.begin(), v[i].first.end());
        }

        // unordered_map<string, int> mp;
        // vector<vector<string>> res;
        // int idx=0;
        // for(int i=0; i<v.size(); ++i){
        //     if(mp.find(v[i].first)!=mp.end());
        // }

        vector<vector<string>> res;
        sort(v.begin(), v.end());
        vector<string> temp;
        temp.push_back(strs[v[0].second]);
        res.push_back(temp);
        for(int i=1; i<v.size(); ++i){
            if(v[i].first==v[i-1].first){
                int idx = res.size()-1;
                res[idx].push_back(strs[v[i].second]);
            }
            else{
                vector<string> temp1;
                temp1.push_back(strs[v[i].second]);
                res.push_back(temp1);
            }
        }
        return res;
    }
};
