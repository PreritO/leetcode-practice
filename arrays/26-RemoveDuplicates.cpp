class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // goal here is to remove the duplicates in-place and return unique number of elements
        
        // woulda been even easier if we could use another array
        // cuz then we could just essentially have a dict but not the case so.. 
        // lets use 2ptr approach, the first ptr keeping track of where we need to update the array (i.e. no duplicates) and the 2nd ptr iterating the entire array
        // start from the 2nd element, so we can compare it to first
        int left = 1, right = 1;
        while(right < nums.size()) {
            if (nums[right] != nums[right-1]) {
                // great, this means we can iterate the left ptr after inserting the element in place
                nums[left] = nums[right];
                left++;
            }
            right++;
        } 
        return left;
    }
};