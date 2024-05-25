class Solution {
public:
    int maxArea(vector<int>& height) {
        // approach here is to think that the way to maximize area is get the min of left[i] and right[j] * (j-i) and keep
        // track of that and see if we ever have an area greatr than that
        int maxArea=0;
        // these are the two pointers starting on each side
        int leftIdx=0, rightIdx=height.size()-1;
        int runningArea = 0;
        while(leftIdx < rightIdx)
        {
            runningArea = min(height[leftIdx],height[rightIdx])*(rightIdx-leftIdx);
            maxArea = max(maxArea, runningArea);
            // the way to maximize the area is to move the index pertaining to the smaller height
            if (height[leftIdx] < height[rightIdx]) { 
                leftIdx++; 
            }
            else { 
                rightIdx--;
            }
        }
        return maxArea; 
    }
};