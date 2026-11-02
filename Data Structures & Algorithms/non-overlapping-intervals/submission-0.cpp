class Solution {
private:
    bool static comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ct=0;
        int prev=0;
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0]<intervals[prev][1]){
                ct++;
            }
            else{
                prev=i;
            }
        }
        
        return ct;
    }
};
