// Source : https://leetcode.com/problems/word-search/
// Author : Nan
// Date   : 2019-03-10
// Runtime: 36 ms

/*
* dfs.
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    int a[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int column = board[0].size();
        int flag = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == word[0]) {
                    char c = board[i][j];
                    board[i][j] = ' ';
                    dfs(board, word, 0, i, j, flag);
                    board[i][j] = c;
                }   
            }
        }
        return flag;
    }
    void dfs(vector<vector<char>>& board, string word, int pos, int i, int j, int &flag) {
        if (flag == 1) {
            return;
        }
        if (pos == (word.length() - 1)) {
            flag = 1;
            return;
        }
        for (int m = 0; m < 4; m++) {
            int ni = i + a[m][0];
            int nj = j + a[m][1];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && board[ni][nj] == word[pos + 1]) {
                char c = board[ni][nj];
                board[ni][nj] = ' ';
                dfs(board, word, pos + 1, ni, nj, flag);
                board[ni][nj] = c;
            }
        }
    }
};