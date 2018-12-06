// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Author : Nan
// Date   : 2018-12-06

/*
* In a sorted n array and a sorted m array, their median is (((m + n + 1) / 2) + ((m + n + 2) / 2)) / 2.0. 
* We can use binary search in both two arrays.  
* 1.If a starting point of a array more than its size, the kth number is in another array.  
* 2.If k is 1, and we can find the answer is min(num1[i], num2[j])  
* 3.ELSE, we can find k/2th number in array1 and array2, if mid1 < mid2, the kth number is in array2 after k/2th. Vice versa.
*
* Time complexity O(log(m+n))
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int a1 = (n + m + 1) / 2, a2 = (n + m + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, a1) + findKth(nums1, 0, nums2, 0, a2)) / 2.0;
    }
    
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if(i >= nums1.size()) return nums2[j + k - 1];
        if(j >= nums2.size()) return nums1[i + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int mid1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int mid2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        return mid1 < mid2 ? findKth(nums1, i + k / 2, nums2, j, k - k / 2) : findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
};
