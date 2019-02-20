// Source : https://leetcode.com/problems/spiral-matrix/
// Author : Nan
// Date   : 2019-02-20
// 22 / 22 test cases passed.
// Runtime: 4 ms

/*
* Simulate. Use four directions.
*
* Time complexity O(mn), Space complexity O(mn)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() < 1) return result;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        result.push_back(matrix[0][0]);
        visit[0][0] = true;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ii, jj, d = 0, i = 0, j = 0;
        while (1) {
            ii = i + dir[d][0];
            jj = j + dir[d][1];
            if (ii < row && ii >= 0 && jj < col && jj >= 0 && visit[ii][jj] == false) {
                i = ii;
                j = jj;
                visit[i][j] = true;
                result.push_back(matrix[i][j]);
            }
            else {
                d = (d + 1) % 4;
                ii = i + dir[d][0];
                jj = j + dir[d][1];
                if (ii >= row || ii < 0 || jj >= col || jj < 0 || visit[ii][jj] == true) {
                    break;
                }
            }
        }
        return result;
    }
};