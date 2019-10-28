// Source : https://leetcode.com/problems/reverse-string
// Author : Nan
// Date   : 2019-10-28
// Runtime: 52 ms

/*
* 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; ++i)
            swap(s[i], s[s.size() - 1 - i]);
    }
};