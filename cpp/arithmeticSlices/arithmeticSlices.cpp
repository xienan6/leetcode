// Source : https://leetcode.com/problems/arithmetic-slices/
// Author : Nan
// Date   : 2020-01-03
// Runtime: 4 ms

/*
* 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, i = 2, start = 0, n = A.size();
        while (i < n) {
            if (n - start < 3) break;
            while (i < n && A[i] - A[i - 1] == A[i - 1] - A[i - 2]) ++i;
            res += (i - start - 1) * (i - start - 2) / 2;
            if (i == n) break;
            else {
                start = i - 1;
                i = start + 2;
            }
        }
        return res;
    }
};