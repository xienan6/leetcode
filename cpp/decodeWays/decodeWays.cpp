// Source : https://leetcode.com/problems/decode-ways
// Author : Nan
// Date   : 2019-01-03
// 258 / 258 test cases passed.
// Runtime: 4 ms

/*
* DP.
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        int m1 = 1, m2 = 1, num;
        for (int i = 1; i < n; i++) {
            num = 0;
            if (s[i] == '0' && !isValid(s[i-1], s[i])) {
                return 0;
            }
            if (s[i] != '0') {
                num = m1;
            }
            if (isValid(s[i-1], s[i])) {
                num += m2;
            }
            m2 = m1;
            m1 = num;
            
        }
        return num;
    }
    
    bool isValid(char a, char b){
        return a == '1' || (a == '2' && b <='6');
    }
};