// Source : https://leetcode.com/problems/combinations
// Author : Nan
// Date   : 2019-03-10
// Runtime: 60 ms

/*
* Recursion.
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        if (k == 0 || n < k) {
            return result;
        }
        for (int i = 1; i <= n; i++) {
            vector<int> temp;
            temp.push_back(i);
            add(result, temp, k - 1, n);
        }
        return result;
    }
    void add(vector<vector<int> > &result, vector<int> v, int k, int n) {
        if (k <= 0) {
            result.push_back(v);
            return;
        }
        for (int i = v[v.size() - 1] + 1; i <= n - k + 1; i++) {
            v.push_back(i);
            add(result, v, k - 1, n);
            v.pop_back();
        }
    }
};