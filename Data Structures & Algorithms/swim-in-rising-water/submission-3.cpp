class Solution {

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        vector<int> dx={-1, 1, 0, 0};
        vector<int> dy={0, 0, 1, -1};

        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            
            int t=cur[0], u=cur[1], v=cur[2];
            if(u==n-1 && v==n-1)
                return t;
            
            // vis[u][v]=1;
            
            for(int i=0; i<4; ++i){
                int nR=u+dx[i], nC=v+dy[i];
                if(nR>=0 && nR<n && nC>=0 && nC<n && !vis[nR][nC]){
                    vis[nR][nC]=1;
                    pq.push({max(t, grid[nR][nC]), nR, nC});
                }
            }
        }
        return -1;
    }
};
