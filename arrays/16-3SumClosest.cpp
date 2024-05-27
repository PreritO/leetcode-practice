class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // approach here is similar to 3sum but now instead of checking if the remaining 
        // right side of array is == 0, we keep track of the minimum distance from the target and return that

        // i.e. sort nums first, then start at each element and treat as pivot, then iterate through right side
        // and check the distance from target, if less than current ongoing min, then set it to that.. 
        sort(nums.begin(), nums.end());
        int difference = INT_MAX;
        int leftPtr, rightPtr = 0, result = 0;
        for(int i = 0; i<nums.size(); i++) {
            leftPtr = i+1;
            rightPtr = nums.size()-1;
            while(leftPtr < rightPtr) {
                int sum = nums[i] + nums[leftPtr] + nums[rightPtr];
                if (abs(sum - target) <= abs(difference)) {
                    difference = sum-target;
                    result = sum; // keep track of this sum
                }
                // now, update the leftPTr and rightPtr based on if sum-target is positive or negative..
                if (sum > target) {
                    rightPtr--;
                } else {
                    leftPtr++;
                }
            }
        }
        return result;
    }
};