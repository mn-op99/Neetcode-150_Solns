class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;

        int lastIdx=0, currIdx=1;
        int maxLength=1;
        unordered_map<char, int> mp;
        mp[s[0]]=0;
        while(currIdx<s.size()){
            char ch = s[currIdx];
            if(mp.find(ch)!=mp.end()){
                int temp = mp[ch];
                for(int i=lastIdx; i<=temp; ++i)
                    mp.erase(s[i]);
                lastIdx = temp+1;
            }
            else{
                maxLength = max(maxLength, currIdx - lastIdx + 1);
            }
            mp[ch]=currIdx;
            currIdx++;
        }
        return maxLength;
    }
};
