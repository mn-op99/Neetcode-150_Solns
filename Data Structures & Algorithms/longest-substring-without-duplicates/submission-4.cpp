class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> asciiArr(255, -1);
        int maxL = 0;
        int l=0, r=0;
        while(r<s.size()){
            int charVal = int(s[r]);
            if(asciiArr[charVal]!=-1)
                l = max(l, asciiArr[charVal]+1);
            asciiArr[charVal]=r;
            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }
};
