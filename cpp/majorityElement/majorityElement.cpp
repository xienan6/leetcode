// Source : https://leetcode.com/problems/majority-element/
// Author : Nan
// Date   : 2019-05-27
// Runtime: 20 ms

/*
* Keep deleting different numbers until there is 
* less or equal than 2 numbers.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {res = num; ++cnt;}
            else (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};