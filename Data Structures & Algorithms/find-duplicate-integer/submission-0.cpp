class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]>0){
                if(nums[nums[i]]<0)
                    return nums[i];
                else
                    nums[nums[i]] = nums[nums[i]]*(-1);
            }
            else{
                if((nums[i]*(-1))==i)
                    return i;
                else{
                    if(nums[nums[i]*(-1)]<0)
                        return nums[i]*(-1);
                    else
                        nums[nums[i]*(-1)] = nums[nums[i]*(-1)]*(-1);
                }
            }
        }
        return 1;
    }
};
