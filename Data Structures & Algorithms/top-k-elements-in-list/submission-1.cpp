class Solution {
public:
    static bool compare(pair<int, int> &x, pair<int, int> &y){
        return x.second < y.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for(auto x: nums){
            m[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it = m.begin(); it!=m.end(); ++it){
            pq.push({it->second, it->first});
            if(pq.size()>k)
                pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
