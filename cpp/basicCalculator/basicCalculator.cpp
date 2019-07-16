// Source : https://leetcode.com/problems/basic-calculator
// Author : Nan
// Date   : 2019-07-16
// Runtime: 8 ms

/*
* Use a stack.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long  result = 0, number = 0, sign = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] <= '9' && s[i] >= '0') {
                number = number * 10 + s[i] - '0';
            }
            else if (s[i] == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            }
            else if (s[i] == ')') {
                result += sign * number;
                number = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        if (number != 0) result += sign * number;
        return result;
    }
};