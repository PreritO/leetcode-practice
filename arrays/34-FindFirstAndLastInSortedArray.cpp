class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // again, we're told that it's a sorted array and to write the algo in log(n) time, alluding to the fact that we can use binary search to find the start and end indices. Only difference being that we want to see if we're looking for the first or last index
        int firstIndex = findIndex(nums, target, true);
        if (firstIndex == -1) {
            return vector<int>{-1,-1};
        }
        int lastIndex = findIndex(nums, target, false);
        return vector<int>{firstIndex, lastIndex};
    }

    int findIndex(vector<int>& nums, int target, bool first) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) {
                // if we're looking for the first index, the way we do that is check what mid is at and if it's equal to the left side, return that
                if(first) {
                    // return the left index here..
                    if (mid==left || nums[mid-1] != target) {
                        return mid;
                    }
                    right = mid-1;
                } else {
                     // else we're looking for the last index, the way we do that is check what mid is at and if it's equal to the right side, return that
                    if (mid==right || nums[mid+1] != target) {
                        return mid;
                    }
                    left = mid+1;
                }
            } else if (nums[mid] > target) {
                // look on the left side..
                right = mid -1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
};