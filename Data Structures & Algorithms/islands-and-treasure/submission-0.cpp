class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==0)
                    q.push({{i, j}, 0});
            }
        }

        int r[]={0, 0, 1, -1};
        int c[]={1, -1, 0, 0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i=0; i<4; ++i){
                int newR = row + r[i];
                int newC = col + c[i];

                if((newR>=0 && newR<m) && (newC>=0 && newC<n) && grid[newR][newC]==2147483647){
                    grid[newR][newC] = dist+1;
                    q.push({{newR, newC}, dist+1});
                }
            }
        }
    }
};
