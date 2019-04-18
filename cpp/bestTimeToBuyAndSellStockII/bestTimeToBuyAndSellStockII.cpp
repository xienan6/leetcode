// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Author : Nan
// Date   : 2019-04-18
// Runtime: 8 ms

/*
* Difference between neighbors.        
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) res += max(0, prices[i] - prices[i - 1]);
        return res;
    }
};