// Source : https://leetcode.com/problems/lexicographical-numbers
// Author : Nan
// Date   : 2019-12-09
// Runtime: 64 ms

/*
* 1. If a number is multiplied by ten and does not exceed n, then it should be ten times next to it.
* 2. If 1 is not satisfied, it should be directly increased by one.
* 3. If 2 is not satisfied, for example, 19 should be followed by 2 instead of 20, and then 19 should be divided by 10 and then added by one.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1; 
        for (int i = 0; i < n; ++i) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur = cur * 10;
            }
            else if (cur % 10 != 9 && cur + 1 <= n) {
                ++cur;
            }
            else {
                while ((cur / 10) % 10 == 9) {
                    cur = cur / 10;
                }
                cur = cur / 10 + 1;
            }
        }
        return res;
    }
};