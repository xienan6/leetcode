// Source : https://leetcode.com/problems/game-of-life/
// Author : Nan
// Date   : 2019-09-18
// Runtime: 0 ms

/*
* Simulate.  
*
* Time complexity O(n^2), Space complexity O(1)
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                getLive(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == -1) board[i][j] = 0;
                else if (board[i][j] == -2) board[i][j] = 1;
            }
        }
    }
    void getLive(vector<vector<int>>& board, int x, int y) {
        int cnt = 0;
        if (x - 1 >= 0) {
            if (y - 1 >= 0) {
                if (abs(board[x - 1][y - 1]) == 1) ++cnt;
            }
            if (abs(board[x - 1][y]) == 1) ++cnt;
            if (y + 1 < board[0].size()){
                if (abs(board[x - 1][y + 1]) == 1) ++cnt;
            }
        }
        if (y - 1 >= 0 && abs(board[x][y - 1]) == 1) ++cnt;
        if (y + 1 < board[0].size() && abs(board[x][y + 1]) == 1) ++cnt;
        if (x + 1 < board.size()) {
            if (y - 1 >= 0) {
                if (abs(board[x + 1][y - 1]) == 1) ++cnt;
            }
            if (abs(board[x + 1][y]) == 1) ++cnt;
            if (y + 1 < board[0].size()){
                if (abs(board[x + 1][y + 1]) == 1) ++cnt;
            }
        }
        if (board[x][y] == 0 && cnt == 3) board[x][y] = -2;
        if (board[x][y] == 1 && cnt != 3 && cnt != 2) board[x][y] = -1;
    }
};