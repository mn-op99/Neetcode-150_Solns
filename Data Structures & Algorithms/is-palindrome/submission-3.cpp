class Solution {
public:
    bool check(char ch){
        return !((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'));
    }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            while(check(s[i]) && i<s.size()){
                ++i;
            }
            while(check(s[j]) && j>=0)
                --j;
            cout<<"s["<<i<<"]="<<s[i]<<" s["<<j<<"]="<<s[j]<<endl;
            if(tolower(s[i])!=tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};
