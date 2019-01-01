// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : Nan
// Date   : 2019-01-01
// 159 / 159 test cases passed.
// Runtime: 36 ms

/*
* In-place algorithm. Use first row and column to 
* store whether this row column need to set zero.
* 
* Time complexity O(mn), Space complexity O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int l = matrix[0].size();
        bool firtColumn = false;
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) {
                firtColumn = true;
            }
            for (int j = 1; j < l; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < l; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < l; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firtColumn) {
            for (int i = 0; i < r; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};