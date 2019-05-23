// Source : https://leetcode.com/problems/compare-version-numbers/
// Author : Nan
// Date   : 2019-05-23
// Runtime: 4 ms

/*
* String processing.   
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, lasti = 0, lastj = 0;
        while (i < version1.length() || j < version2.length()) {
            while (i < version1.length() && version1[i] != '.') ++i;
            while (j < version2.length() && version2[j] != '.') ++j;
            int v1 = lasti < version1.length() ? atoi(version1.substr(lasti, i - lasti).c_str()) : 0; 
            int v2 = lastj < version2.length() ? atoi(version2.substr(lastj, j - lastj).c_str()) : 0;
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            else {
                lasti = (++i);
                lastj = (++j);
            }
        }
        return 0;
    }
};