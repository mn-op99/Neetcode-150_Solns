class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); ++i){
            mp[s[i]]=i;
        }
        vector<int> res;
        int currMax=0, start=0;
        for(int i=0; i<s.size(); ++i){
            if(mp[s[i]]>i){
                currMax=max(currMax, mp[s[i]]);
            }
            else{
                if(currMax>i)
                    continue;
                else{
                    int numElements = i-start+1;
                    res.push_back(numElements);
                    start=i+1;
                }
            }
        }
        return res;
    }
};
