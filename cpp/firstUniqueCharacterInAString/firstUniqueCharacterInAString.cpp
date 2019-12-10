// Source : https://leetcode.com/problems/first-unique-character-in-a-string
// Author : Nan
// Date   : 2019-12-09
// Runtime: 32 ms

/*
* Hash.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); ++i) ++v[s[i] - 'a'];
        for (int i = 0; i < s.length(); ++i) {
            if (v[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};