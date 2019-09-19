// Source : https://leetcode.com/problems/word-pattern/
// Author : Nan
// Date   : 2019-09-19
// Runtime: 0 ms

/*
* Two-way hashmap.  
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int i = 0, j = 0;
        while (i < pattern.length() && j < str.length()) {
            int start = j;
            while (j < str.length() && str[j++] != ' ') ;
            string s = j < str.length() ? str.substr(start, j - start - 1) : str.substr(start, j - start);
            if (m2.find(s) != m2.end() && (m1.find(pattern[i]) == m1.end() || m2[s] != pattern[i])) return false;
            if (m1.find(pattern[i]) != m1.end() && (m2.find(s) == m2.end() || m1[pattern[i]] != s)) return false;
            m1[pattern[i]] = s;
            m2[s] = pattern[i++];
        }
        return i == pattern.length() && j == str.length() ? true : false;
    }
};