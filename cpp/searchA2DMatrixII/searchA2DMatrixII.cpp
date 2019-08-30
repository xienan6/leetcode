// Source : https://leetcode.com/problems/search-a-2d-matrix-ii
// Author : Nan
// Date   : 2019-08-30
// Runtime: 68 ms

/*
* Find from upper right corner. If it is greater than target, erase a column. If it is smaller than target, erase a row.
*
* Time complexity O(n+m), Space complexity O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false; 
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};