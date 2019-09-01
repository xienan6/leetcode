// Source : https://leetcode.com/problems/valid-anagram/
// Author : Nan
// Date   : 2019-09-01
// Runtime: 12 ms

/*
* Calculate times of alphabets if they are equal.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26, 0);
        for (int i = 0; i < s.length(); ++i) ++alphabet[s[i] - 'a'];
        for (int i = 0; i < t.length(); ++i) --alphabet[t[i] - 'a']; 
        for (int i = 0; i < 26; ++i) if (alphabet[i] != 0) return false;
        return true;
    }
};