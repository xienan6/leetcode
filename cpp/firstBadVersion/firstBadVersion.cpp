// Source : https://leetcode.com/problems/first-bad-version/
// Author : Nan
// Date   : 2019-09-11
// Runtime: 0 ms

/*
* Binary search.
*
* Time complexity O(logn), Space complexity O(1)
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 1, upper = n, mid;
        while(lower < upper) {
            mid = lower + (upper - lower) / 2;
            if(!isBadVersion(mid)) lower = mid + 1;
            else upper = mid;
        }
        return lower;
    }
};