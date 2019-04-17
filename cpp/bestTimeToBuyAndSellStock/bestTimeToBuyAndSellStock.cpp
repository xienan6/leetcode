// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Nan
// Date   : 2019-04-17
// Runtime: 8 ms

/*
* Find max difference.        
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int res = 0, m = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            res = max(res, prices[i] - m);
            m = min(m, prices[i]);
        }
        return res;
    }
};