// Source : https://leetcode.com/problems/maximum-product-of-word-lengths
// Author : Nan
// Date   : 2019-10-13
// Runtime: 64 ms

/*
* Use bits of a 32-bit integer to represent a mask of a string. Then use & to check every bit.
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> mask(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if (!(mask[i] & mask[j])) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};