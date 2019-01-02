// Source : https://leetcode.com/problems/combination-sum/
// Author : Nan
// Date   : 2019-01-02
// 168 / 168 test cases passed.
// Runtime: 20 ms

/*
* Recursive.  
* 
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        dfs(result, target, 0, {}, candidates);
        return result;
    }
    void dfs(vector<vector<int>> &result, int target, int start, vector<int> r, vector<int> &candidates) {
        if (target < 0) return;
        else if (target == 0) {
            result.push_back(r);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            r.push_back(candidates[i]);
            dfs(result, target - candidates[i], i, r, candidates);
            r.pop_back();
        }
    }
};