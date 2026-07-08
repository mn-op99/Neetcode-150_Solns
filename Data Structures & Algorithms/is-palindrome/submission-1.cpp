class Solution {
public:
    bool isPalindrome(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        string s="";
        for(char x: str){
            if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9'))
                s += x;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        cout<<rev<<endl;
        return rev==s;
    }
};
