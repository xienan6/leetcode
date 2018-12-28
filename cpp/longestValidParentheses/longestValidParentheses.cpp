// Source : https://leetcode.com/problems/longest-valid-parentheses
// Author : Nan
// Date   : 2018-12-28
// 230 / 230 test cases passed.
// Runtime: 8 ms

/*
* Use a stack record the index of '(' and a start 
* records longest valid parentheses index. When meet 
* a ')', if stack is empty, start records angin and 
* if stack is not empty, pop and find the max.  
* 
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), result = 0, start = 0;
        stack<int> st;
        if (n <= 1) return 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (st.empty()) start = i + 1;
                else {
                    st.pop();
                    result = st.empty() ? max(result, i - start + 1) : max(result, i - st.top());
                }
            }
        }
        return result;
    }
};