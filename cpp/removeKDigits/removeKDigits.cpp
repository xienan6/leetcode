// Source : https://leetcode.com/problems/remove-k-digits/
// Author : Nan
// Date   : 2019-12-26
// Runtime: 4 ms

/*
* Use a monotonic stack.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};