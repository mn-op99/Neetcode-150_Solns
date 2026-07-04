class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for(char x: s){
            m[x]++;
        }
        for(char x: t){
            m[x]--;
            if(m[x]==0)
                m.erase(x);
        }
        return m.size()==0;
    }
};
