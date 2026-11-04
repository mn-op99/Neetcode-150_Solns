class Solution {
private:
    int sumDigitSquare(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;;
            sum += rem*rem;
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        int slowPtr=n, fastPtr=n;
        fastPtr = sumDigitSquare(fastPtr);
        fastPtr = sumDigitSquare(fastPtr);
        
        while(slowPtr!=fastPtr){
            slowPtr = sumDigitSquare(slowPtr);
            fastPtr = sumDigitSquare(fastPtr);
            fastPtr = sumDigitSquare(fastPtr);
            if(fastPtr==1)
                return true;
        }
        return false;
    }
};
