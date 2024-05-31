class Solution {
public:

    void build_sol(int remaining_target, vector<int>& curr_comb, int startIdx, vector<int>& candidates, vector<vector<int>>& res) {
        // base case is if we have no more elements that need to be added to curr_comb to get to target (tracked by remaining_target), then we can add curr_comb to results and return
        if (remaining_target == 0) {
            res.push_back(curr_comb);
            return;
        }

        // also if we've already had the sum exceed the target, we don't want to add curr_comb to the results and just return early
        if (remaining_target < 0) {
            return;
        }

        // now we want to try every possible solution an dcall build_sol to see when we either hit target or go over it (caught by cases above)
        for(int i = startIdx; i<candidates.size(); i++) {
            int value = candidates[i];
            curr_comb.push_back(value);
            build_sol(remaining_target-value, curr_comb, i, candidates, res);
            curr_comb.pop_back();
        } 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // okay, so because we want ALL the possible combinations, this yells a backtracking type of algo where we slowly build up the solution...
        // key insight here is that we can repeat the same element multiple times if needed! let's create the template for backtracking here.. 
        vector<vector<int>> res;
        vector<int> curr_comb;
        build_sol(target, curr_comb, 0, candidates, res);
        return res;
    }
};