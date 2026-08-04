class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int r[], int c[]){
        vis[i][j]=1;

        int ct=0;
        for(int k=0; k<4; ++k){
            int newR=i+r[k];
            int newC=j+c[k];
            if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && grid[newR][newC]==1 && vis[newR][newC]==0){
                ct += 1 + dfs(newR, newC, grid, vis, r, c);
            }
        }
        return ct;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, 1, -1};

        int area=0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(grid[i][j]==1 && vis[i][j]==0)
                    area = max(area, 1+dfs(i, j, grid, vis, r, c));
        return area;
    }
};
