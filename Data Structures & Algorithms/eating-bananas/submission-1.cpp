class Solution {
public:
    int solve(vector<int> &piles, int k){
        int hCal=0;
        for(auto x: piles){
            hCal += x/k;
            if((x%k)!=0)
                hCal++;
        }
        return hCal;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal=INT_MIN;
        for(auto x: piles){
            maxVal = max(maxVal, x);
        }

        int l=1, r=maxVal;
        while(l<=r){
            int mid = l+(r-l)/2;
            int hCal = solve(piles, mid);
            if(hCal<=h)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};
