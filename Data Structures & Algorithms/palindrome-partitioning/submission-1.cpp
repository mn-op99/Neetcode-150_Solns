class Solution {
private:
    bool check(string &s){
        string t = s;
        reverse(t.begin(), t.end());
        return t==s;
    }
    void solve(int i, string &s, vector<string> &temp, vector<vector<string>> &res){
        if(i==s.size()){
            res.push_back(temp);
            return;
        }

        for(int idx=i; idx<s.size(); ++idx){
            string str = s.substr(i, idx-i+1);
            if(check(str)){
                temp.push_back(str);
                solve(idx+1, s, temp, res);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(0, s, temp, res);
        return res;
    }
};
