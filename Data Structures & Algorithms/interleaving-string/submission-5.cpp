class Solution {
private:
    bool solve(int i, int j, int k, string s1, string s2, string s3, vector<vector<vector<int>>> &dp){
        if(k==s3.size()-1){
            if(i<s1.size()){
                return s3[k]==s1[i];
            }
            else{
                return s3[k]==s2[j];
            }
        }

        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        bool val1=false, val2=false;
        if(i<s1.size() && s3[k]==s1[i])
            val1 = solve(i+1, j, k+1, s1, s2, s3, dp);
        if(j<s2.size() && s3[k]==s2[j])
            val2 = solve(i, j+1, k+1, s1, s2, s3, dp);
        
        return dp[i][j][k] = (val1 || val2);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size(), y=s3.size();
        if(n==0 && m==0 && y==0)
            return true;
        if(n+m!=y)
            return false;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(y+1, -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};
