// Source : https://leetcode.com/problems/wildcard-matching/
// Author : Nan
// Date   : 2019-01-15
// 1808 / 1808 test cases passed.
// Runtime: 24 ms

/*
* Use two pointers in both string. Detailed in code.  
*
* Time complexity O(n+m), Space complexity O(1)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int si = -1, sj = -1, i = 0, j = 0, l1 = s.length(), l2 = p.length(); 
        while (i < l1){
			//advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that j will not advance beyond its length
            if (p[j] == '?' || s[i] == p[j]) {
                i++;
                j++;
                continue;
            }
			// * found in pattern, track index of *, only advancing pattern pointer 
            if (p[j] == '*') {
                si = i;
                sj = j++;
                continue;
            }
			//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (sj >= 0) { 
                i = ++si;
                j = sj + 1;
                continue;
            }
			//current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            return false;
        }
		//check for remaining characters in pattern
        while (p[j]=='*' && j < l2) j++;
        return l2 == j;   
    }
};