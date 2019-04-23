// Source : https://leetcode.com/problems/surrounded-regions/
// Author : Nan
// Date   : 2019-04-23
// Runtime: 44 ms

/*
* Use DFS to find all 'O' on the border and change it to 
* another character. Then change all remaining 'O' to 'X'.
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (checkPoint(i, j, board.size(), board[0].size()) == 1 && board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'K') board[i][j] = 'O';
            }
        }
    }
    void dfs(int x, int y, vector<vector<char>>& board) {
        board[x][y] = 'K';
        for (int i = 0; i < 4; ++i) {
            if (checkPoint(x + dir[i][0], y + dir[i][1], board.size(), board[0].size()) != 0 && board[x + dir[i][0]][y + dir[i][1]] == 'O') {
                dfs(x + dir[i][0], y + dir[i][1], board);
            }
        }
    }
    int checkPoint(int x, int y, int size1, int size2) {
        if (x >= 1 && x <= size1 - 2 && y >= 1 && y <= size2 - 2) return 2;
        else if (x < 0 || x >= size1 || y < 0 || y >= size2) return 0;
        else return 1;
    }
};