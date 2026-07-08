class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i=0; i<strs.size(); ++i){
            res += to_string(strs[i].size()) +  "*" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int starting_idx = 0;
        for(int i=0; i<s.size(); ++i){
            char ch = s[i];
            if(ch>=48 && ch<=57){
                // cout<<i<<" ";
                continue;
            }
            else{
                string num = s.substr(starting_idx, i-starting_idx);
                int size = stoi(num);
                string temp = s.substr(i+1, size);
                strs.push_back(temp);
                starting_idx = i+size+1;
                i += size;
            }
        }
        return strs;
    }
};
