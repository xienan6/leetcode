// Source : https://leetcode.com/problems/longest-common-prefix/description/
// Author : Nan
// Date   : 2018-12-15
// 118 / 118 test cases passed.
// Runtime: 8 ms

/*
* Compare all strs from start.  
* 
* Time complexity O(nm), Space complexity O(1)  
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        int i = 0, l = strs[0].length();
        bool flag = false;
        for (i; i < l; i++) {
            for (int j = 1; j < n; j++) {
                if (strs[j][i] != strs[0][i]) flag = true;
            }
            if (flag) break;
        }
        return strs[0].substr(0, i);
    }
};