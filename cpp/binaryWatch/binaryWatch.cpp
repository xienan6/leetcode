// Source : https://leetcode.com/problems/binary-watch/
// Author : Nan
// Date   : 2019-12-25
// Runtime: 4 ms

/*
* Recursion solution.
*
* Time complexity O(-), Space complexity O(-)
*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if (num == 0) return {"0:00"};
        vector<string> res;
        vector<bool> v(10, false);
        // int aa = 0;
        // cout << to_string(aa) << endl;
        for (int i = 0; i <= 10 - num; ++i) {
            helper(res, num - 1, i, v);
        }
        return res;
    }
    void helper(vector<string> &res, int n, int s, vector<bool> v) {
        v[s] = true;
        if (n == 0) {
            int hour = 0, minute = 0;
            for (int i = 0; i < 4; ++i) {
                hour += v[i] == true ? (int)pow(2, i) : 0;
            }
            for (int i = 4; i < 10; ++i) {
                minute += v[i] == true ? (int)pow(2, i - 4) : 0;
            }
            if (hour >= 12 || minute >= 60) return;
            string r = "";
            if (hour == 0) r += "0:";
            else r += to_string(hour) + ":";
            if (minute < 10) r += ("0" + to_string(minute));
            else r += to_string(minute);
            res.push_back(r);
        }
        else {
            for (int i = s + 1; i <= 10 - n; ++i) {
                helper(res, n - 1, i, v);
            }
        }
    }
};