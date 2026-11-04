class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.begin(), digits.end());
        int carry=0;
        int sum=0;
        for(int i=res.size()-1; i>=0; --i){
            if(i==res.size()-1)
                sum = res[i]+1;
            else
                sum=res[i]+carry;
            if(sum>9){
                sum=sum%10;
                carry=1;
            }
            else
                carry=0;
            res[i]=sum;
        }
        if(carry==1)
            res.insert(res.begin(), 1);
        return res;
    }
};
