class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end())
            return "";
        else{
            int l=0, r=m[key].size()-1;
            int mid;
            while(l<=r){
                mid = l+(r-l)/2;
                if(m[key][mid].first==timestamp)
                    return m[key][mid].second;
                else if(m[key][mid].first>timestamp)
                    r=mid-1;
                else
                    l=mid+1;
            }
            if(r<0)
                return "";
            return m[key][r].second;
        }
    }
};