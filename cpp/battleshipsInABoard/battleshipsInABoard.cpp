// Source : https://leetcode.com/problems/battleships-in-a-board/
// Author : Nan
// Date   : 2020-01-08
// Runtime: 8 ms

/*
* A X with its left and top is not X is a prow.
*
* Time complexity O(nm), Space complexity O(1)
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (!(board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X'))) 
                    ++res;
            }
        }
        return res;
    }
};