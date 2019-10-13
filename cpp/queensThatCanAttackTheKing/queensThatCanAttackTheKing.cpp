// Source : https://leetcode.com/problems/queens-that-can-attack-the-king/
// Author : Nan
// Date   : 2019-10-13
// Runtime: 4 ms

/*
* Check the nearest queen of 8 directions.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        vector<vector<int>> t(8, {-1, -1});
        for (int i = 0; i < queens.size(); ++i) {
            if (king[0] == queens[i][0] && king[1] < queens[i][1]) {
                if (t[2][1] == -1) t[2] = queens[i];
                else if (t[2][1] > queens[i][1]) t[2] = queens[i];
            }
            else if (king[0] == queens[i][0] && king[1] > queens[i][1]) {
                if (t[6][1] == -1) t[6] = queens[i];
                else if (t[6][1] < queens[i][1]) t[6] = queens[i];
            }
            else if (king[1] == queens[i][1] && king[0] < queens[i][0]) {
                if (t[4][0] == -1) t[4] = queens[i];
                else if (t[4][0] > queens[i][0]) t[4] = queens[i];
            }
            else if (king[1] == queens[i][1] && king[0] > queens[i][0]) {
                if (t[0][0] == -1) t[0] = queens[i];
                else if (t[0][0] < queens[i][0]) t[0] = queens[i];
            }
            else if (king[0] - queens[i][0] > 0 && king[0] - queens[i][0] == queens[i][1] - king[1]) {
                if (t[1][0] == -1) t[1] = queens[i];
                else if (t[1][0] < queens[i][0]) t[1] = queens[i];
            }
            else if (king[0] - queens[i][0] < 0 && king[0] - queens[i][0] == king[1] - queens[i][1]) {
                if (t[3][0] == -1) t[3] = queens[i];
                else if (t[3][0] > queens[i][0]) t[3] = queens[i];
            }
            else if (king[0] - queens[i][0] < 0 && king[0] - queens[i][0] == queens[i][1] - king[1]) {
                if (t[5][0] == -1) t[5] = queens[i];
                else if (t[5][0] > queens[i][0]) t[5] = queens[i];
            }
            else if (king[0] - queens[i][0] > 0 && king[0] - queens[i][0] == king[1] - queens[i][1]) {
                if (t[7][0] == -1) t[7] = queens[i];
                else if (t[7][0] < queens[i][0]) t[7] = queens[i];
            }
        }
        for (int i = 0; i < 8; ++i) {
            if (t[i][1] != -1) res.push_back(t[i]);
        }
        return res;
    }
};