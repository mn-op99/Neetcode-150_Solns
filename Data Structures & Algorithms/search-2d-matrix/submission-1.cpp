class Solution {
public:
    int searchRow(vector<vector<int>> &matrix, int l, int r, int target) {

        if (l > r)
            return r;

        int mid = l + (r - l) / 2;

        if (matrix[mid][0] == target)
            return mid;

        if (matrix[mid][0] < target)
            return searchRow(matrix, mid + 1, r, target);
        else
            return searchRow(matrix, l, mid - 1, target);
    }

    int searchCol(vector<vector<int>> &matrix, int row, int l, int r, int target) {

        if (l > r)
            return -1;

        int mid = l + (r - l) / 2;

        if (matrix[row][mid] == target)
            return mid;

        if (matrix[row][mid] < target)
            return searchCol(matrix, row, mid + 1, r, target);
        else
            return searchCol(matrix, row, l, mid - 1, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = searchRow(matrix, 0, matrix.size() - 1, target);

        if (row == -1)
            return false;

        return searchCol(matrix, row, 0, matrix[0].size() - 1, target) != -1;
    }
};