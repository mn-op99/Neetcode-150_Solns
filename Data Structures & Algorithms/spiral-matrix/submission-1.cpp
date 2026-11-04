class Solution {
private:
    void solve(int i, int j, int dir,
               vector<int> &r, vector<int> &c,
               vector<vector<int>> &matrix,
               vector<int> &res,
               vector<vector<int>> &vis) {

        int m = matrix.size();
        int n = matrix[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j])
            return;

        res.push_back(matrix[i][j]);
        vis[i][j] = 1;

        int newR = i + r[dir];
        int newC = j + c[dir];

        // Change direction if next cell is invalid or visited
        if(newR < 0 || newR >= m ||
           newC < 0 || newC >= n ||
           vis[newR][newC]) {

            dir = (dir + 1) % 4;
        }

        solve(i + r[dir], j + c[dir], dir, r, c, matrix, res, vis);
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> r = {0, 1, 0, -1};
        vector<int> c = {1, 0, -1, 0};

        vector<int> res;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        solve(0, 0, 0, r, c, matrix, res, vis);

        return res;
    }
};