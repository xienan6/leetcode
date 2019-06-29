// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author : Nan
// Date   : 2019-06-29
// Runtime: 8 ms

/*
* DP. Switch between two states "hold" and "sold".
*
* Time complexity O(nk), Space complexity O(k)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), res = 0;
        if (n < 2) return 0;
        if (k > n / 2) {
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }
        vector<int> hold(k + 1, INT_MIN);
        vector<int> sold(k + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                hold[j] = max(hold[j], sold[j - 1] - prices[i]);
                sold[j] = max(sold[j], hold[j] + prices[i]);
            }
        }
        return sold[k];
    }
};