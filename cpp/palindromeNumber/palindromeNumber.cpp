// Source : https://leetcode.com/problems/palindrome-number/
// Author : Nan
// Date   : 2018-12-11
// 11509 / 11509 test cases passed.
// Runtime: 172 ms

/*
* You can only reverse till half and then compare two number.
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0|| (x != 0 && x % 10 == 0)) return false;
        int sum = x % 10;
        x /= 10;
        while(x > sum) {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};