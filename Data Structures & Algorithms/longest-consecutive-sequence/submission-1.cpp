class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        set<int> m;
        for(auto x: nums){
            m.insert(x);
        }

        int ct=1;
        int ans=1;
        for(auto x: nums){
            if(m.find(x-1)==m.end()){
                while(m.find(x+1)!=m.end()){
                    ct++;
                    x+=1;
                }
                ans = max(ans, ct);
                ct=1;
            }
        }
        return ans;
    }
};
