// Source : https://leetcode.com/problems/reconstruct-original-digits-from-english
// Author : Nan
// Date   : 2020-01-11
// Runtime: 28 ms

/*
* 
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<string> words{"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}, counts(26, 0);
        vector<char> chars{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        for (char c : s) ++counts[c - 'a'];
        for (int i = 0; i < 10; ++i) {
            int cnt = counts[chars[i] - 'a'];
            for (int j = 0; j < words[i].size(); ++j) {
                counts[words[i][j] - 'a'] -= cnt;
            }
            while (cnt--) res += (nums[i] + '0');
        }
        sort(res.begin(), res.end());
        return res;
    }
};