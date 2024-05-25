class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //mapping is digit(key) -> index(value)
        unordered_map<int,int> nmap; 
        vector<int> result;
        for(int i = 0; i<nums.size(); i++){
            //compare digit we're looking for in map
            int comp = target - nums[i]; 
            if(nmap.find(comp) == nmap.end()){
                // if doesn't exist in map, set it
                nmap[nums[i]] = i;
            } else {
                // else get the index and comp idx and return
                result.push_back((nmap.at(comp)));
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};