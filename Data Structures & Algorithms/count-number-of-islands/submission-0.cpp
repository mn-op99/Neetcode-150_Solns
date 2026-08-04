class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int r[], int c[]){
        vis[i][j]=1;

        for(int k=0; k<4; ++k){
            int newRow = i+r[k];
            int newCol = j+c[k];
            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]=='1' && vis[newRow][newCol]==0){
                dfs(newRow, newCol, grid, vis, r, c);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, 1, -1};

        int numOfIslands=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    numOfIslands++;
                    dfs(i, j, grid, vis, r, c);
                }
            }
        }
        return numOfIslands;
    }
};