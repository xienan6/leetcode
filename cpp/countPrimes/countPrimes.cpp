// Source : https://leetcode.com/problems/count-primes/
// Author : Nan
// Date   : 2019-06-13
// Runtime: 68 ms

/*
* Prime sieve. 
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> v(n, true);
        int res = 1;
        for (int k = 2; k * 2 < n; ++k) v[k * 2] = false;
        for (int i = 3; i < n; i += 2) {
            if (v[i]) {
                ++res;
                for (int k = 2; k * i < n; ++k) v[k * i] = false;
            }
        }
        return res;
    }
};