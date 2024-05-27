class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // this is really not that different from removing the duplicates in place.. all we need to check is if the current value is not equal to the val. If it isn't, we can move that to the running front of the array and then return the count.. 
        int left = 0, right = 0;
        while(right < nums.size()) {
            if(nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};