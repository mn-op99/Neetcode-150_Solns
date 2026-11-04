class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        int val=abs(x);
        while(val>0){
            int rem=val%10;
            rev = rev*10 + rem;
            val=val/10;
        }
        if(rev>INT_MAX || -rev<INT_MIN)
            return 0;
        else
            return x>0?rev:-rev;
    }
};
