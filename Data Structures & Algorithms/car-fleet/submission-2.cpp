class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for(int i=0; i<position.size(); ++i)
            v.push_back({position[i], speed[i]});
        
        sort(v.begin(), v.end());

        int ct=1;
        auto nextCar=v[v.size()-1];
        for(int i=v.size()-2; i>=0; --i){
            double hopsCurr = (double)(target-v[i].first)/v[i].second;
            double hopsNext = (double)(target-nextCar.first)/nextCar.second;
            if(hopsCurr<=hopsNext)
                continue;
            else{
                ct++;
                nextCar = v[i];
            }
        }
        return ct;
    }
};
