// Source : https://leetcode.com/problems/maximum-number-of-balloons/
// Author : Nan
// Date   : 2019-09-15
// Runtime: 8 ms

/*
* Count letters.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < text.length(); ++i) {
            cnt[text[i] - 'a']++;
        }
        return min(min(min(cnt[0], cnt[1]), min(cnt[11], cnt[14]) / 2), cnt[13]);
    }
};