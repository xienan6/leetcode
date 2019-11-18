// Source : https://leetcode.com/problems/counting-bits
// Author : Nan
// Date   : 2019-11-18
// Runtime: 52 ms

/*
* DP.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i) res[i] = res[i >> 1] + (i % 2);
        return res;
    }
};