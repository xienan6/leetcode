// Source : https://leetcode.com/problems/reverse-integer/description/
// Author : Nan
// Date   : 2018-12-09
// 1032 / 1032 test cases passed.
// Runtime: 16 ms

/*
* INT_MAX = 2147483647 and INT_MIN = -2147483648. 
* You can compare your result with them and judge if it is overflow. 
* You can also use a long long to store result and compare it with INT_MAX and INT_MIN.
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x) {
            int pop = x % 10;
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
            if(result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;
            result = result * 10 + pop;
            x /= 10;
        }
        return result;
    }
}; 
