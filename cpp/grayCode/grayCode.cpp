// Source : https://leetcode.com/problems/gray-code/
// Author : Nan
// Date   : 2019-03-18
// Runtime: 8 ms

/*
* -     
*
* Time complexity O(2^n), Space complexity O(2^n)
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};