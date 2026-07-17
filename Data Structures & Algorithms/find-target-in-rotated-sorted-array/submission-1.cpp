class Solution {
public:
    int searchMinIdx(vector<int> &nums, int l, int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]>nums[r]){
                if(nums[l]>nums[mid])
                    r=mid;
                else
                    l=mid+1;
            }
            else{
                return  l;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int minIdx = searchMinIdx(nums, 0, n-1);
        int offset = minIdx;
        int l = 0, r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[(mid+offset+n)%n]==target)
                return (mid+offset+n)%n;
            else if(nums[(mid+offset+n)%n]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};
