class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int x=0; x<n/2; ++x){
            for(int y=x; y<n-x-1; ++y){
                swap(matrix[x][y], matrix[y][n-x-1]);
                swap(matrix[x][y], matrix[n-x-1][n-y-1]);
                swap(matrix[x][y], matrix[n-y-1][x]);
            }
        }
    }
};