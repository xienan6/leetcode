// Source : https://leetcode.com/problems/valid-sudoku/description/
// Author : Nan
// Date   : 2018-12-14
//504 / 504 test cases passed.
// Runtime: 16 ms

/*
* You only need to check the filled cells if they are valid. 
* So we can design a hash to check in O(n^2) time. Notice that (i, j) 
* cell is in No.(i / 3 * 3 + j / 3) 3x3 box, so we can use three hash 
*refereed each 3x3 box, each row and each row.
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool inBox[9][9] = {false}, inCol[9][9] = {false}, inRow[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = i / 3 * 3 + j / 3;
                    int y = board[i][j] - '1';
                    if (inBox[x][y] || inCol[j][y] || inRow[i][y]) return false;
                    inBox[x][y] = inCol[j][y] = inRow[i][y] = true;
                }
            }
        }
        return true;
    }
};