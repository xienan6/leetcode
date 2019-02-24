// Source : https://leetcode.com/problems/spiral-matrix-ii
// Author : Nan
// Date   : 2019-02-23
// 20 / 20 test cases passed.
// Runtime: 8 ms

/*
* Use four boundaries guarantee output.  
* 
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int total = n * n, num = 1, rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;
        while(num <= total){
            for(int y = colBegin; y <= colEnd; y++)
                res[rowBegin][y] = num++;
            rowBegin++;  
            for(int x = rowBegin; x <= rowEnd; x++)
                res[x][colEnd] = num++;
            colEnd--; 
            for(int y = colEnd; y >= colBegin; y--)
                res[rowEnd][y] = num++;
            rowEnd--; 
            for(int x = rowEnd; x >= rowBegin; x--)
                res[x][colBegin] = num++;
            colBegin++; 
        }
        return res;
    }
};