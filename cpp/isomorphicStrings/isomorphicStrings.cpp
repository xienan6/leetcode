// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : Nan
// Date   : 2019-06-14
// Runtime: 12 ms

/*
* Two-way hashmap. 
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash1;
        unordered_map<char, char> hash2;
        for (int i = 0; i < s.length(); ++i) {
            if (hash1.find(s[i]) == hash1.end()) hash1[s[i]] = t[i];
            else if (hash1[s[i]] != t[i]) return false;
            if (hash2.find(t[i]) == hash2.end()) hash2[t[i]] = s[i];
            else if (hash2[t[i]] != s[i]) return false;
        }
        return true;
    }
};