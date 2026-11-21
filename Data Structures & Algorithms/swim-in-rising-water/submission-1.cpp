class Solution {
private:
    bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &dx, vector<int> &dy, int water, int n){
        if(i==n-1 && j==n-1)
            return true;
        vis[i][j]=1;

        for(int idx=0; idx<4; ++idx){
            int nR = i+dx[idx], nC = j+dy[idx];
            if(nR>=0 && nR<n && nC>=0 && nC<n && !vis[nR][nC] && grid[nR][nC]<=water){
                if(dfs(nR, nC, grid, vis, dx, dy, water, n))
                    return true;
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int maxVal=-1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                maxVal=max(maxVal, grid[i][j]);
        }

        int l=0, r=maxVal;
        vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(l<r){
            int mid = l+(r-l)/2;
            vector<vector<int>> vis(n, vector<int>(n, 0)); 
            bool res = false;
            if(grid[0][0]<=mid)
                res = dfs(0, 0, grid, vis, dx, dy, mid, n);
            if(res){
                r=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
};
