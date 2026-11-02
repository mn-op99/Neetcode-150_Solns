class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        int ctFreshFruit=0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==1)
                    ctFreshFruit++;
                if(grid[i][j]==2)
                    q.push({{i, j}, 0});
            }
        }

        int r[] = {0, 0, 1, -1};
        int c[] = {1, -1, 0, 0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int min = q.front().second;
            res = max(res, min);
            q.pop();

            for(int i=0; i<4; ++i){
                int newR = row + r[i];
                int newC = col + c[i];
                if((newR>=0 && newR<grid.size()) && (newC>=0 && newC<grid[0].size()) && (grid[newR][newC]==1)){
                    grid[newR][newC]=2;
                    q.push({{newR, newC}, min+1});
                    ctFreshFruit--;
                }
            }
        }

        if(ctFreshFruit!=0)
            return -1;
        else
            return res;
    }
};
