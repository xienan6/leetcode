// Source : https://leetcode.com/problems/add-digits/
// Author : Nan
// Date   : 2019-09-03
// Runtime: 0 ms

/*
* Find the law.  
*
* Time complexity O(1), Space complexity O(1)
*/

class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : (num - 1) % 9 + 1;
    }
};