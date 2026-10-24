class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;
        while(left<right){
            while(left<right && (s[left]<'A' || s[left]>'Z') && (s[left]<'a' || s[left]>'z') && (s[left]<'0' || s[left]>'9')){
                left++;
            }
            while(left<right && (s[right]<'A' || s[right]>'Z') && (s[right]<'a' || s[right]>'z') && (s[right]<'0' || s[right]>'9')){
                right--;
            }
            if (s[left] == s[right] ||
    ((s[left] >= 'A' && s[left] <= 'Z') &&
     s[left] + 32 == s[right]) ||
    ((s[right] >= 'A' && s[right] <= 'Z') &&
     s[right] + 32 == s[left])) {
    left++;
    right--;
} else {
    return false;
}
        }
        return true;
    }
};
