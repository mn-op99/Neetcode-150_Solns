class Solution {
private:
    int count(int n){
        return __builtin_popcount(n);
    }
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; ++i)
            res.push_back(count(i));
        return res;
    }
};
