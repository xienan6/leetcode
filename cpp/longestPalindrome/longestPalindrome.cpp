// Source : https://leetcode.com/problems/longest-palindrome/
// Author : Nan
// Date   : 2019-12-31
// Runtime: 8 ms

/*
* Almost one odd number of character.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> t;
        for (char c : s) {
            if (!t.count(c)) t.insert(c);
            else t.erase(c);
        }
        return s.size() - max(0, (int)t.size() - 1);
    }
};