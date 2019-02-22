// Source : https://leetcode.com/problems/length-of-last-word
// Author : Nan
// Date   : 2019-02-22
// 59 / 59 test cases passed.
// Runtime: 4 ms

/*
* Simulate. 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, result = 0;
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i--] != ' ') result++;
        return result;
    }
};