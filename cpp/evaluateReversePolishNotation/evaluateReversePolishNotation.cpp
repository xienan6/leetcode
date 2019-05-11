// Source : https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author : Nan
// Date   : 2019-05-11
// Runtime: 16 ms

/*
* Use a stack.      
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].length() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/')) {
                int a = s.top();s.pop();
                int b = s.top();s.pop();
                if (tokens[i][0] == '+') s.push(b + a);
                if (tokens[i][0] == '-') s.push(b - a);
                if (tokens[i][0] == '*') s.push(b * a);
                if (tokens[i][0] == '/') s.push(b / a);
            }
            else s.push(atoi(tokens[i].c_str()));
        }
        return s.top();
    }
};