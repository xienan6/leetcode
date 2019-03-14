// Source : https://leetcode.com/problems/largest-rectangle-in-histogram
// Author : Nan
// Date   : 2019-03-14
// Runtime: 12 ms

/*
* Use a stack to maintain a non-decreasing sequence. 
* When meet a num is less than stack.top, calculate the max area.  
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};