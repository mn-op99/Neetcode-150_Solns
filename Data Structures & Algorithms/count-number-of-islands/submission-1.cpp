class Solution {
private:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int r[], int c[], queue<pair<int, int>> &q){
        q.push({i, j});
        vis[i][j]=1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0; k<4; ++k){
                int newR = row + r[k];
                int newC = col + c[k];
                if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && grid[newR][newC]=='1' && vis[newR][newC]==0){
                    q.push({newR, newC});
                    vis[newR][newC]=1;
                }
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
        queue<pair<int, int>> q;

        int numOfIslands=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    numOfIslands++;
                    bfs(i, j, grid, vis, r, c, q);
                }
            }
        }
        return numOfIslands;
    }
};