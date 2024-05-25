class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        // approach is to first sort the nums array O(nlogn)
        // then if we only have positive numbers, we can't have the distinct numbers add up to zero
        // so there can be no triplets.. 
        sort(nums.begin(), nums.end());
        
        // following is O(n^2)
        for(int i = 0; i<nums.size(); i++){
            if (nums[i] > 0) { break; }
            // we don't want to take into consideration repeating elements which will be right next to each other after sorting..
            if (i == 0 || nums[i]!=nums[i-1]){
                // use two pointers to then loop through the rest of the array
                int left = i+1;
                int right = nums.size()-1;

                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right];
                    // two pointer solution, if number is too large, move down, else move up.. 
                    if (sum > 0) { right--;}
                    else if (sum < 0) { left++;}
                    else {
                        // we found a 0!
                        results.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left]==nums[left-1]){
                            left++;
                        }
                    }
                }
            }
        }
        
        return results;
    }
};