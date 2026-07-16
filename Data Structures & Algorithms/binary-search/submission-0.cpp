class Solution {
public:
    int binSearch(vector<int> &nums, int l, int r, int target){
        if(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                return binSearch(nums, mid+1, r, target);
            else
                return binSearch(nums, l, mid-1, target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size()-1, target);
    }
};
