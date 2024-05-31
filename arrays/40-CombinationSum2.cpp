class Solution {
public:
    void build_sol(int remaining_target, vector<int>& curr_comb, int startIdx, vector<int>& candidates, vector<vector<int>>& res) {
        // again, this is the base case if we have no more elements that need to be added to curr_comb to get to target (tracked by remaining_target), then we can add curr_comb to results and return
        if (remaining_target == 0) {
            res.push_back(curr_comb);
            return;
        }

        // now we want to try every possible unique solution and call build_sol to see when we  hit the target
        for(int i = startIdx; i<candidates.size(); i++) {
            // let's handle duplicates here..
            int value = candidates[i];
            if (i > startIdx && value == candidates[i-1]) {
                // skip this
                continue;
            }

            if (value <= remaining_target) {
                curr_comb.push_back(value);
                // unlike the previous problem, we're looking for unique solutions so we can't add exisiting index so move it to the next one.. 
                build_sol(remaining_target-value, curr_comb, i+1, candidates, res);
                curr_comb.pop_back();
            }
        } 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // okay, so because we want just unique possible combinations, this yells a backtracking type of algo where we slowly build up the solution just like combinationSum but now we just want to gloss over the duplicate numbers.. so let's use same template as before but one thing that might help is if we were to sort the candidate list session so that the duplicates are right next to each other and we can skip over them
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr_comb;
        build_sol(target, curr_comb, 0, candidates, res);
        return res;
    }
};