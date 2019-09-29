// Source : https://leetcode.com/problems/range-sum-query-mutable/
// Author : Nan
// Date   : 2019-09-29
// Runtime: 32 ms

/*
* DP.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = -prices[0], sell = 0, prebuy = 0, presell = 0;
        for (int i = 0; i < prices.size(); ++i) {
            prebuy = buy;
            buy = max(prebuy, presell - prices[i]);
            presell = sell;
            sell = max(presell, prebuy + prices[i]);
        }
        return sell;
    }
};