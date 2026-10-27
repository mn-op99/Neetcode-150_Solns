class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ct=0;
        for(int i=0; i<n; ++i){
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                ct++;
                l--;
                r++;
            }
            
            if(i>0 && s[i]==s[i-1]){
                l=i-1, r=i;
                while(l>=0 && r<n && s[l]==s[r]){
                    ct++;
                    l--;
                    r++;
                }
            }
        }
        return ct;
    }
};
