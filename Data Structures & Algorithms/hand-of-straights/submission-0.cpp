
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        // Store frequency of each card in sorted order
        map<int, int> mp;

        for(int x : hand) {
            mp[x]++;
        }

        // Traverse cards in increasing order
        for(auto &it : mp) {

            int curr = it.first;

            // No cards remaining
            if(it.second == 0)
                continue;

            int freq = it.second;

            // Form a consecutive group
            for(int j = 0; j < groupSize; j++) {

                int card = curr + j;

                if(mp[card] < freq)
                    return false;

                mp[card] -= freq;
            }
        }

        return true;
    }
};
