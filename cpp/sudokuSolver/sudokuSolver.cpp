// Source : https://leetcode.com/problems/sudoku-solver
// Author : Nan
// Date   : 2018-12-14
// 6 / 6 test cases passed.
// Runtime: 4 ms

/*
* Use three hash in Valid Sudoku. Then Retrospective method or dfs.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> inBox(9, vector<bool>(9, false));
        vector<vector<bool>> inRow(9, vector<bool>(9, false));
        vector<vector<bool>> inCol(9, vector<bool>(9, false));
        bool flag = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    inCol[j][num] = inRow[i][num] = inBox[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        sudokuSolver(board, 0, 0, inBox, inCol, inRow, flag);
    }
    void sudokuSolver(vector<vector<char>>& b, int i, int j, vector<vector<bool>>& inBox, vector<vector<bool>>& inCol, vector<vector<bool>>& inRow, bool &flag) {
        int nx = (j == 8 ? i + 1 : i);
        int ny = (j == 8 ? 0 : j + 1);
        if (b[i][j] == '.') {
            for (int k = 0; k < 9; k++) {
                int numBox = i / 3 * 3 + j / 3;
                if (!inBox[numBox][k] && !inCol[j][k] && !inRow[i][k]) {
                    inBox[numBox][k] = inCol[j][k] = inRow[i][k] = true;
                    b[i][j] = (char)k + '1';
                    if (i == 8 && j == 8) {
                        flag = true;
                        return;
                    }
                    sudokuSolver(b, nx, ny, inBox, inCol, inRow, flag);
                    if (flag) return;
                    inBox[numBox][k] = inCol[j][k] = inRow[i][k] = false;
                }
            }
            b[i][j] = '.';
            return;
        }
        else {
            if (i == 8 && j == 8) {
                flag = true;
                return;
            }
            sudokuSolver(b, nx, ny, inBox, inCol, inRow, flag);
        }
    }
};
