// Source : https://leetcode.com/problems/string-to-integer-atoi/description/
// Author : Nan
// Date   : 2018-12-06

/*
* simulate 
*
* Time complexity O(n)
*/

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int i = 0, result = 1, bit = 0;
        long ans = 0;
        while (str[i] == ' ') {i++;}
        if ((str[i] > '9' || str[i] < '0') && (str[i] != '-' && str[i] != '+')) {
            return 0;
        }
        else {
            if (str[i] == '-') {
                result = -1;
                i++;
            }
            else if (str[i] == '+') {
                i++;
            }
            while (str[i] <= '9' && str[i] >= '0') {
                ans = ans * 10 + (str[i] - '0');
                if (ans > INT_MAX && result == -1) {
                        return INT_MIN;
                    }
                else if (ans > INT_MAX && result == 1) {
                    return INT_MAX;
                }
                i++;
            }
        }
        result = result * ans;
        return result;
    }
};
