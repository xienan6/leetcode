// Source : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author : Nan
// Date   : 2019-09-15
// Runtime: 4 ms

/*
* Recursion solution.  
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        int begin=0, end=n-1;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                begin = i;
            if(s[i] == ')'){
                end = i;
                string temp = s.substr(begin + 1, end - begin - 1);
                reverse(temp.begin(),temp.end());
                return reverseParentheses(s.substr(0, begin) + temp + s.substr(end + 1));
             }
        }
        return s;
    }
};