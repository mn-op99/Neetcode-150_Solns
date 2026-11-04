class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x=1.0/x;
            n=-n;
        }
        
        double res=1.0;
        while(n>0){
            if((n&1)>0)
                res=res*x;
            x=x*x;
            n=n/2;
        }
        return res;
    }
};
