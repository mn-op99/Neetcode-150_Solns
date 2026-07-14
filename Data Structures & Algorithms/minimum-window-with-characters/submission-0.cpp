class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mt, ms;

        for (char ch : t)
            mt[ch]++;

        int l = 0;
        int have = 0;
        int need = t.size();

        int minL = INT_MAX;
        int minI = -1;

        for (int r = 0; r < s.size(); r++) {

            char ch = s[r];

            if (mt.find(ch) != mt.end()) {
                ms[ch]++;

                if (ms[ch] <= mt[ch])
                    have++;
            }

            while (have == need) {

                if (r - l + 1 < minL) {
                    minL = r - l + 1;
                    minI = l;
                }

                if (mt.find(s[l]) != mt.end()) {
                    ms[s[l]]--;

                    if (ms[s[l]] < mt[s[l]])
                        have--;
                }

                l++;
            }
        }

        if (minI == -1)
            return "";

        return s.substr(minI, minL);
    }
};