class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row(9), col(9);
        vector<vector<unordered_map<char, int>>> smallBox(3, vector<unordered_map<char, int>>(3));
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]>=48 && board[i][j]<=57){
                    if(row[i][board[i][j]]>0)
                        return false;
                    if(col[j][board[i][j]]>0)
                        return false;
                    if(smallBox[i/3][j/3][board[i][j]]>0)
                        return false;
                    row[i][board[i][j]]++;
                    col[j][board[i][j]]++;
                    smallBox[i/3][j/3][board[i][j]]++;
                }
            }
        }
        return true;
    }
};
