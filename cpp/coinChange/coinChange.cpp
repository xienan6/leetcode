// Source : https://leetcode.com/problems/coin-change/
// Author : Nan
// Date   : 2019-10-16
// Runtime: 8 ms

/*
* Recursion solution. 
*
* Time complexity O(nm), Space complexity O(nm)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = amount + 1;
        sort(coins.rbegin(), coins.rend());
        f(coins, 0, res, 0, amount);
        return res == amount + 1 ? -1 : res;
    }
    void f(vector<int> &coins, int idx, int &res, int curr, int amount) {
        if (amount == 0) {
            res = min(res, curr);
            return;
        }
        if (idx == coins.size()) return;
        for (int i = amount / coins[idx]; i >= 0 && curr + i < res; --i) 
            f(coins, idx + 1, res, curr + i, amount - i * coins[idx]);
    }
};