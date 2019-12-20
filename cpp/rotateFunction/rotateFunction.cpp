// Source : https://leetcode.com/problems/rotate-function/
// Author : Nan
// Date   : 2019-12-20
// Runtime: 8 ms

/*
* F(i) = F(0) + sum - n * A[n - i]
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long t = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            t += i * A[i];
        }
        long long res = t;
        for (int i = 1; i < n; ++i) {
            t = t + sum - n * A[n - i];
            res = max(res, t);
        }
        return res;
    }
};