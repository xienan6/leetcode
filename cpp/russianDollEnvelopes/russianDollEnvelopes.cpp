// Source : https://leetcode.com/problems/russian-doll-envelopes
// Author : Nan
// Date   : 2019-11-05
// Runtime: 640 ms

/*
* Sort and LIS.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};