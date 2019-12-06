// Source : https://leetcode.com/problems/ransom-note
// Author : Nan
// Date   : 2019-12-06
// Runtime: 20 ms

/*
* Count the number of letters.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < magazine.length(); ++i) cnt[magazine[i] - 'a']++;
        for (int i = 0; i < ransomNote.length(); ++i) {
            cnt[ransomNote[i] - 'a']--;
            if (cnt[ransomNote[i] - 'a'] < 0) return false;
        }
        return true;
    }
};