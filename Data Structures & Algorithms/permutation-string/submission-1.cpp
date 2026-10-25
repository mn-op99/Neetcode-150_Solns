class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(int i=0; i<s1.size(); ++i){
            mp1[s1[i]]++;
        }
        for(int i=0; i<s1.size(); ++i){
            mp2[s2[i]]++;
        }
        if(mp1==mp2)
            return true;
        int left = 0;
        for(int i=s1.size(); i<s2.size(); ++i){
            mp2[s2[left]]--;
            if(mp2[s2[left]]==0)
                mp2.erase(s2[left]);
            mp2[s2[i]]++;
            if(mp1==mp2)
                return true;
            left++;
        }
        return false;
    }
};
