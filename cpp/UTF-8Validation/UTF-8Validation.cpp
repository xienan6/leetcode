// Source : https://leetcode.com/problems/utf-8-validation/
// Author : Nan
// Date   : 2019-12-17
// Runtime: 12 ms

/*
* Traversal.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty()) return true;
        int re = remain(data[0]), i = 1;
        while (i < data.size()) {
            if (re == 5) return false;
            else if (re == 1) {
                re = remain(data[i++]);
            }
            else {
                while (re > 1 && i < data.size()) {
                    if ((data[i++] & 128) == 128) --re;
                    else return false;
                }
            }
        }
        return re == 1;
    }
    int remain(int d) {
        if ((d & 240) == 240 && d < 248) return 4;
        else if ((d & 224) == 224) return 3;
        else if ((d & 192) == 192) return 2;
        else if ((d & 128) == 0) return 1;
        else return 5;
    }
};