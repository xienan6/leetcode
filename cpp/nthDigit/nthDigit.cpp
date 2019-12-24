// Source : https://leetcode.com/problems/nth-digit/
// Author : Nan
// Date   : 2019-12-24
// Runtime: 4 ms

/*
* Recursion solution.
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int findNthDigit(int n) {
        long long nn = n;
        int i = 0;
        while (nn > 0) {
            ++i;
            nn -= 9 * (long long)pow(10, i - 1) * i;
        }
        nn += 9 * (long long)pow(10, i - 1) * i;
        long long a = (long long)pow(10, i - 1) + nn / i;
        if (nn % i == 0) return (a - 1) % 10;
        else if (nn % i == 1) return a / (int)pow(10, i - 1);
        else return a % (int)pow(10, i + 1 - nn % i) / (long long)pow(10, i - nn % i);
    }
};