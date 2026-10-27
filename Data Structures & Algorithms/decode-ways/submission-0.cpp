class Solution {
private:
    int solve(int i, string s, vector<int> &dp){
        if(i>=s.size()){
            return 1;
        }

        if(s[i]=='0')
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int val1 = solve(i+1, s, dp);
        int val2=0;
        if((i+1)<s.size()){
            int valInt = stoi(s.substr(i, 2));
            if(valInt>=10 && valInt<=26)
                val2 = solve(i+2, s, dp);
        }
        return dp[i] = val1 + val2;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};
