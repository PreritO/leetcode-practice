class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // approach here is similar to 3sum but now instead of checking if the remaining 
        // right side of array is == 0, we keep track of the minimum distance from the target and return that

        // i.e. sort nums first, then start at each element and treat as pivot, then iterate through right side
        // and check the distance from target, if less than current ongoing min, then set it to that.. 

        sort(nums.begin(), nums.end());
        int difference = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            if (difference == 0) {
                // we can't get a smaller difference!
                break;
            }
            int leftPtr = i+1;
            int rightPtr = nums.size()-1;
            while(leftPtr < rightPtr) {
                int sum = nums[i] + nums[leftPtr] + nums[rightPtr];
                if (abs(target-sum) < abs(difference)) {
                    difference = target-sum;
                }
                // now, update the leftPTr and rightPtr based on if sum-target is positive or negative..
                if (target-sum > 0) {
                    rightPtr--;
                } else {
                    leftPtr++;
                }
            }
        }
        // sum = target Number - lowest diff here..
        return target-difference;
    }
};