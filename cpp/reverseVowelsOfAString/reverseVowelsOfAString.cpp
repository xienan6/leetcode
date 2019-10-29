// Source : https://leetcode.com/problems/reverse-vowels-of-a-string
// Author : Nan
// Date   : 2019-10-29
// Runtime: 12 ms

/*
* 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
    bool isVowel(char c) {
        if (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u' || c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U') return true;
        else return false;
    }
};