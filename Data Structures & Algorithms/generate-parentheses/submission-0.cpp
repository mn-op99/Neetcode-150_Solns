class Solution {
private:
    void solve(int i, int ctOpen, int ctClose, int n, string &temp, vector<string> &res){
        if(i==2*n){
            res.push_back(temp);
            return;
        }

        if(ctOpen>0){
            temp += '(';
            solve(i+1, ctOpen-1, ctClose, n, temp, res);
            temp.pop_back();
        }
        if(ctOpen<ctClose && ctClose>0){
            temp += ')';
            solve(i+1, ctOpen, ctClose-1, n, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        solve(0, n, n, n, temp, res);
        return res;
    }
};
