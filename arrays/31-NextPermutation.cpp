class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // start from the end
        int n = nums.size();
        int i = n-2;

        // 1. Find the first number from the end that breaks the descending order
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }

        // if array is sorted in descending manner, there is no next permutation
        if(i < 0) { 
            reverse(nums.begin(), nums.end()); 
            return; 
        }

        // 2. Now find smallest elment from the right that is just greater than current element
        int j = n-1;
        while(j >= 0 && nums[j] <= nums[i]){
            j--;
        }
        // swap those element
        swap(nums[i], nums[j]);
        // reverse elements from nums[i] to end
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};