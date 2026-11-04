class Solution {
private:
    bool check(int row, int col, vector<string> &board){
        for(int r=0; r<row; ++r){
            if(board[r][col]=='Q')
                return false;
        }
        for(int c=0; c<col; ++c){
            if(board[row][c]=='Q')
                return false;
        }
        int tempR=row, tempC=col;
        while(tempR>=0 && tempC>=0){
            if(board[tempR][tempC]=='Q')
                return false;
            tempR--;
            tempC--;
        }
        tempR=row, tempC=col;
        while(tempR>=0 && tempC>=0 && tempC<board[0].size()){
            if(board[tempR][tempC]=='Q')
                return false;
            tempR--;
            tempC++;
        }
        return true;
    }
    void solve(int row, vector<string> &board, vector<vector<string>> &res){
        if(row==board.size()){
            res.push_back(board);
            return;
        }

        for(int col=0; col<board.size(); ++col){
            if(check(row, col, board)){
                board[row][col] = 'Q';
                solve(row+1, board, res);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        solve(0, board, res);
        return res;
    }
};
