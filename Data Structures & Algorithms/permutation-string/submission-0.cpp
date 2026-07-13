class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;

        for (char ch : s1)
            m1[ch]++;

        int l = 0;

        for (int r = 0; r < s2.size(); r++) {

            char ch = s2[r];

            // Character not present in s1
            if (m1.find(ch) == m1.end()) {
                m2.clear();
                l = r + 1;
                continue;
            }

            m2[ch]++;

            // If frequency exceeds allowed frequency,
            // shrink window until it becomes valid.
            while (m2[ch] > m1[ch]) {
                m2[s2[l]]--;
                if (m2[s2[l]] == 0)
                    m2.erase(s2[l]);
                l++;
            }

            // Window size became equal to s1 length
            if (r - l + 1 == s1.size())
                return true;
        }

        return false;
    }
};
