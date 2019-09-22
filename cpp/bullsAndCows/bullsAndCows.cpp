// Source : https://leetcode.com/problems/bulls-and-cows/
// Author : Nan
// Date   : 2019-09-21
// Runtime: 0 ms

/*
* Count numbers.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt1 = 0, cnt2 = 0;
        vector<int> cnt(10, 0);
        for (int i = 0; i < guess.length(); ++i) {
            if (secret[i] == guess[i]) ++cnt1;
            else ++cnt[guess[i] - '0'];
        }
        for (int i = 0; i < guess.length(); ++i) {
            if (cnt[secret[i] - '0'] && secret[i] != guess[i]) {
                ++cnt2;
                --cnt[secret[i] - '0'];
            }
        }
        return to_string(cnt1) + "A" + to_string(cnt2) + "B";
    }
};