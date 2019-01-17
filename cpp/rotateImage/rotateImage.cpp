// Source : https://leetcode.com/problems/rotate-image/
// Author : Nan
// Date   : 2019-01-17
// 21 / 21 test cases passed.
// Runtime: 4 ms

/*
* Simulate.    
*
* Time complexity O(n^2), Space complexity O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n - 1 - 2 * i; j++) {
                int a = matrix[i][i + j];
                matrix[i][i + j] = matrix[n - i - j - 1][i];
                matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
                matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
                matrix[i + j][n - 1 - i] = a;
            }
        }
    }
};