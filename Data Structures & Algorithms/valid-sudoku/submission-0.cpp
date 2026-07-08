class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> row(9);
        vector<unordered_map<int, int>> col(9);
        vector<vector<unordered_map<int, int>>> box(3, vector<unordered_map<int, int>>(3));

        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                char ch = board[i][j];
                if(ch>='1' && ch<='9'){
                    row[i][ch-'1']++;
                    col[j][ch-'1']++;
                    box[i/3][j/3][ch-'1']++;
                }
            }
        }

        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                char ch = board[i][j];
                if(ch>='1' && ch<='9'){
                    if(row[i].find(ch-'1')!=row[i].end()){
                        if(row[i][ch-'1']>1)
                            return false;
                    }
                    if(col[j].find(ch-'1')!=col[j].end()){
                        if(col[j][ch-'1']>1)
                            return false;
                    }
                    if(box[i/3][j/3].find(ch-'1')!=box[i/3][j/3].end()){
                        if(box[i/3][j/3][ch-'1']>1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
