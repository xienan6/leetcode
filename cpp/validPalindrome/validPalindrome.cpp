// Source : https://leetcode.com/problems/valid-palindrome/
// Author : Nan
// Date   : 2019-01-14
// 476 / 476 test cases passed.
// Runtime: 4 ms

/*
* Use two pointers from left and right.  
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    static bool isAlphanumeric(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
    static bool isSame(char c1, char c2) {
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 32;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 32;
        }
        return c1 == c2;
    }
    bool isPalindrome(string s) {
        int l = s.length();
        int i = 0, j = l - 1;
        while (1) {
            while (isAlphanumeric(s[i]) == false && i < j) {
                i++;   
            }
            while (isAlphanumeric(s[j]) == false && i < j) {
                j--;
            }
            if (isAlphanumeric(s[i]) && isAlphanumeric(s[j]) && i < j) {
                if (isSame(s[i], s[j]) == false) {
                    return false;
                }
                else {
                    i++;
                    j--;
                }
            }
            if (i >= j) {
                return true;
            }
        }
        
    }
};