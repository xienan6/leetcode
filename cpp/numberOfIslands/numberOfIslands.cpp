// Source : https://leetcode.com/problems/number-of-islands/
// Author : Nan
// Date   : 2019-06-08
// Runtime: 16 ms

/*
* DFS.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ++res;
                }
            }
        }
        return res;
    }
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '2';
        if (x + 1 < grid.size() && grid[x + 1][y] == '1') dfs(x + 1, y, grid);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') dfs(x, y + 1, grid);
        if (x - 1 >= 0 && grid[x - 1][y] == '1') dfs(x - 1, y, grid);
        if (y - 1 >= 0 && grid[x][y - 1] == '1') dfs(x, y - 1, grid);
    }
};