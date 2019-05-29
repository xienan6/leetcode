// Source : https://leetcode.com/problems/factorial-trailing-zeroes/
// Author : Nan
// Date   : 2019-05-29
// Runtime: 0 ms

/*
* Count 10 means count 2 * 5. Because 2 is more than 5, 
* we need to calculate 5. Notice 25, 125, etc.
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while (n) {     //count the number of factor 5;
            count += n/5;
            n /= 5;
        }
        return count;
    }
};