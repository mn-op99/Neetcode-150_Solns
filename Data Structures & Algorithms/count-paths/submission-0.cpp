class Solution {
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m && j==n)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int right=0, down=0;
        if(j+1<=n)
            right = solve(i, j+1, m, n, dp);
        if(i+1<=m)
            down = solve(i+1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(1, 1, m, n, dp);
    }
};
