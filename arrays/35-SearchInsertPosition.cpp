class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // again, if we're required to write an algo in log(n) time and array is sorted already, just use binary search
        int mid = 0, left = 0, right=nums.size()-1;
        while(left<=right) {
            //mid accounting for overflow will be the following:
            mid = left + (right-left)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};