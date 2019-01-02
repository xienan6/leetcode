// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : Nan
// Date   : 2019-01-02
// 59 / 59 test cases passed.
// Runtime: 4 ms

/*
* Merge from end.
* 
* Time complexity O(m+n), Space complexity O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i];
                i--;
            }
            else {
                nums1[k--] = nums2[j];
                j--;
            }
        }
        if (i < 0) {
            while (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
        if (j < 0) {
            while (i >= 0) {
                nums1[k--] = nums1[i--];
            }
        }
    }
};