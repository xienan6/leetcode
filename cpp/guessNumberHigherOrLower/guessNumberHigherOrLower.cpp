// Source : https://leetcode.com/problems/guess-number-higher-or-lower/
// Author : Nan
// Date   : 2019-11-23
// Runtime: 4 ms

/*
* Binary search.
*
* Time complexity O(logn), Space complexity O(1)
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            int ans = guess(mid);
            if (ans == 0) break;
            else if (ans == -1) right = mid - 1;
            else left = mid + 1;
        }
        return mid;
    }
};