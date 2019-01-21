// Source : https://leetcode.com/problems/n-queens-ii/
// Author : Nan
// Date   : 2019-01-21
// 304 / 304 test cases passed.
// Runtime: 24 ms

/*
* DFS.  
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> r;
        string s = "";
        for (int i = 0; i < n; i++) s += '.';
        for (int i = 0; i < n; i++) r.push_back(s);
        for (int j = 0; j < n; j++) {
            queen(result, r, 0, j, n);
        }
        return result;
    }
    void queen(int  &result, vector<string> r, int x, int y, int n) {
        r[x][y] = 'Q';
        if (x == n - 1) {
            result += 1;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (judge(x + 1, j, r, n)) {
                queen(result, r, x + 1, j, n);
            }
        }
        
    }
    bool judge(int x, int y, vector<string> r, int n) {
        for (int i = 0; i < x; i++) {
            if (r[i][y] == 'Q') return false;
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (r[i][j] == 'Q') return false;
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (r[i][j] == 'Q') return false;
        }
        return true;
    }
};