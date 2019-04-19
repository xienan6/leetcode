// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author : Nan
// Date   : 2019-04-19
// Runtime: 8 ms

/*
* DP. We define local[i][j] as the maximum profit that 
* can be made for a maximum of j transactions on the ith day 
* and the last transaction on the last day, which is locally 
* optimal. Then we define global[i][j] as the maximum profit 
* that can be traded up to j times on the ith day, which is the 
* global optimal. 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int g[3] = {0}, l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};