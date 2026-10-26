
class Solution {
private:
    bool check(vector<int>& mapS, vector<int>& mapT) {
        for (int j = 0; j < 128; ++j) {
            if (mapS[j] < mapT[j]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        vector<int> mapS(128, 0), mapT(128, 0);

        for (unsigned char c : t) {
            mapT[c]++;
        }

        int lastIdx = 0;
        int resL = 0;
        int minLen = INT_MAX;

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char ch = s[i];
            mapS[ch]++;

            if (check(mapS, mapT)) {
                while (lastIdx <= i) {
                    unsigned char ch1 = s[lastIdx];

                    if (mapT[ch1] == 0) {
                        lastIdx++;
                    }
                    else if (mapS[ch1] > mapT[ch1]) {
                        mapS[ch1]--;
                        lastIdx++;
                    }
                    else {
                        break;
                    }
                }

                int len = i - lastIdx + 1;

                if (len < minLen) {
                    minLen = len;
                    resL = lastIdx;
                }
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(resL, minLen);
    }
};
