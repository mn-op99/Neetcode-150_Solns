class Solution {
private:
    bool solve(int i, int j, int idx, vector<int> &r, vector<int> &c, vector<vector<char>>& board, string &word, vector<vector<int>> &vis){
        if(idx==(word.size()-1))
            return true;

        vis[i][j]=1;
        for(int ind=0; ind<4; ++ind){
            int newR = i+r[ind], newC=j+c[ind];
            if((newR>=0 && newR<board.size()) && (newC>=0 && newC<board[0].size()) && (!vis[newR][newC] && word[idx+1]==board[newR][newC])){
                if(solve(newR, newC, idx+1, r, c, board, word, vis))
                    return true;
            }
        }
        vis[i][j]=0;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(), col=board[0].size();
        vector<int> r={0, 0, 1, -1};
        vector<int> c={1, -1, 0, 0};
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(board[i][j]==word[0]){
                    if(solve(i, j, 0, r, c, board, word, vis))
                        return true;
                    vis.assign(row, vector<int>(col, 0));
                }
            }
        }
        return false;
    }
};
