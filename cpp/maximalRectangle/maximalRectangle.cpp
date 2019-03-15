// Source : https://leetcode.com/problems/maximal-rectangle
// Author : Nan
// Date   : 2019-03-15
// Runtime: 24 ms

/*
* Think of each line as a largest rectangle in histogram.  
* Use a stack to maintain a non-decreasing sequence. 
* When meet a num is less than stack.top, calculate the max area.  
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int height[row][col + 1];
        for (int i = 0; i < row; i++) height[i][col] = 0;
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == '1') height[0][j] = 1;
            else height[0][j] = 0;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') height[i][j] = height[i - 1][j] + 1;
                else height[i][j] = 0;
            }
        }
        int res = 0;
        for (int i = 0; i < row; i++) {
            stack<int> st;
            for (int j = 0; j < col + 1; j++) {
                while (!st.empty() && height[i][st.top()] >= height[i][j]) {
                    int cur = st.top(); st.pop();
                    res = max(res, height[i][cur] * (st.empty() ? j : (j - st.top() - 1)));
                }
                st.push(j);
            }
        }
        return res;
    }
};