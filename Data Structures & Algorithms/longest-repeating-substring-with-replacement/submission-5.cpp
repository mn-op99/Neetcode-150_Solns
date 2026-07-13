class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxRes = 0;
        for(int i=65; i<=90; ++i){
            char ch = char(i);
            int l = 0, changes = 0;

            for (int r = 0; r < s.size(); r++) {

                if (s[r] != ch)
                    changes++;

                while (changes > k) {
                    if (s[l] != ch)
                        changes--;
                    l++;
                }

                maxRes = max(maxRes, r - l + 1);
            }
        }
        return maxRes;
    }
};