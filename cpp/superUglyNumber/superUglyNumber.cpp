// Source : https://leetcode.com/problems/super-ugly-number/
// Author : Nan
// Date   : 2019-10-10
// Runtime: 228 ms

/*
* Find the smallest ugly number each time and push it in vector.
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1), idx(primes.size(), 0);
        while (res.size() < n) {
            vector<int> tmp;
            int mn = INT_MAX;
            for (int i = 0; i < primes.size(); ++i) tmp.push_back(res[idx[i]] * primes[i]);
            for (int i = 0; i < primes.size(); ++i) mn = min(mn, tmp[i]);
            for (int i = 0; i < primes.size(); ++i) if (mn == tmp[i]) ++idx[i];
            res.push_back(mn);
        }
        return res.back();
    }
};