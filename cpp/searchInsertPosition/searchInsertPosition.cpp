// Source : https://leetcode.com/problems/search-insert-position/
// Author : Nan
// Date   : 2018-12-31
// 62 / 62 test cases passed.
// Runtime: 8 ms

/*
* Binary search.  
* 
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        long begin = 1, end = x, mid;
        long xx = x;
        if (x == 0) {
            return 0;
        }
        while (1) {
            mid = (begin + end) >> 1;
            if (mid * mid > xx) {
                end = mid;
            }
            else if ((mid + 1) * (mid + 1) <= xx){
                begin = mid;
            }
            else {
                return mid;
            }
        }
    }
};