// Source : https://leetcode.com/problems/integer-replacement/
// Author : Nan
// Date   : 2019-12-21
// Runtime: 0 ms

/*
* If n is even, replace n with n/2.
* If n is odd and (n + 1) % 4 == 0 and n is not 3, 
* replace n with either n + 1, else replace n with n - 1.
*
* Time complexity O(n / 2), Space complexity O(1)
*/

class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long long t = n;
        while (t != 1) {
            if (t & 1 == 1) {
                if ((t + 1) % 4 == 0 && t != 3) ++t;
                else --t;
            }
            else {
                t >>= 1;
            }
            ++res;
        }
        return res;
    }
};