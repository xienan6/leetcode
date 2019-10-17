// Source : https://leetcode.com/problems/wiggle-sort-ii
// Author : Nan
// Date   : 2019-10-17
// Runtime: 72 ms

/*
* Find the median. If a number is bigger than the median, put it in an even number. Otherwise, put it in an odd number.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), i = 0, j = 0, k = n - 1;
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        while (j <= k) {
            if (A(j) > mid) swap(A(i++), A(j++));
            else if (A(j) < mid) swap(A(j), A(k--));
            else ++j;
        }
    }
};