class Solution {
public:
    int search(vector<int>& nums, int target) {
        // key hints here are that nums is already sorted and we're asked to do this in log(n) time hinting at using binary search... 
        // so let's start off with doing a binary search to first find the pivot. Given it's already sorted, we can choose the middle index, compare it to what should be the largest value (at the last index). If it's greater, it means the pivot must be on the right, else pivot is on the left. After that binary search, we can then also check if target exists and if does, return its index..
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = (left + right)/2;
            if(nums[mid] > nums[nums.size()-1]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        // now we know the pivot meaning that from 0 to left is sorted, and left+1 to nums.size() is sorted so we can jsut do a binary search on each side for target..
        int res = binarySearch(nums, 0, left, target);
        if (res == -1) {
            res = binarySearch(nums,left, nums.size()-1, target);
        }
        return res;
    }

    int binarySearch(vector<int>& nums, int startIdx, int endIdx, int target) {
        int left = startIdx, right = endIdx;
        while (left <= right) {
            int mid = (left+right)/2;
            if (nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
};