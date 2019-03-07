// Source : https://leetcode.com/problems/search-a-2d-matrix
// Author : Nan
// Date   : 2019-03-07
// 136 / 136 cases passed.
// Runtime: 12 ms

/*
* Binary search. Notice index convertion.     
*
* Time complexity O(log(nm)), Space complexity O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[row - 1][col - 1]) return false;
        int left = 0, right = row * col - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int i = mid / col, j = mid % col;
            if (matrix[i][j] < target) left = mid + 1;
            else if (matrix[i][j] > target) right = mid - 1;
            else return true;
        }
        return false;
    }
};