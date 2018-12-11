// Source : https://leetcode.com/problems/valid-parentheses/description/
// Author : Nan
// Date   : 2018-12-11


/*
* Use s stack and pop when meet a corresponding )]}
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> in;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                in.push(s[i]);
                continue;
            }
            else if (in.size() > 0 && 
                     ((s[i] == ')' && in.top() == '(') || (s[i] == '}' && in.top() == '{') || (s[i] == ']' && in.top() == '['))) {
                in.pop();
            }
            else {
                return false;
            }
        }
        if (in.empty() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};