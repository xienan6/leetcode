// Source : https://leetcode.com/problems/combination-sum-iii/
// Author : Nan
// Date   : 2019-06-28
// Runtime: 4 ms

/*
* Recursive.
*
* Time complexity O(1), Space complexity O(1)
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        for (int i = 1; i <= 9; ++i) {
            vector<int> r(1, i);
            dfs(res, r, k - 1, n - i);
        }
        return res;
    }
    void dfs(vector<vector<int>> &s, vector<int> r, int k, int n) {
        if (9 * k < n || k * r.back() + k > n || k < 0 || n < 0) return;
        if (k == 0 && n == 0) {
            s.push_back(r);
            return;
        }
        for (int i = r.back() + 1; i <= 9; ++i) {
            r.push_back(i);
            dfs(s, r, k - 1, n - i);
            r.pop_back();
        }
    }
};