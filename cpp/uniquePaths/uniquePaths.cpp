// Source : https://leetcode.com/problems/unique-paths
// Author : Nan
// Date   : 2019-02-26
// 62 / 62 cases passed.
// Runtime: 4 ms

/*
* Think about permutations. You can only choose down 
* and right with and order. Select min(m-1,n-1) points 
* in m+n-2 points. 
* 
* Time complexity O(min(n,m)), Space complexity O(1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int small = m > n ? n - 1 : m - 1;
        double fz = 1, fm = 1; 
        for (int i = 1; i <= small; i++) {
            fz *= (m + n - 1 - i);
            fm *= i;
        }
        return (int)(fz / fm);
    }
};