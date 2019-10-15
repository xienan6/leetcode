// Source : https://leetcode.com/problems/create-maximum-number/
// Author : Nan
// Date   : 2019-10-15
// Runtime: 28 ms

/*
* Step1: pick out k numbers from an array to form the largest number.
* Step2: compare two arrays until they compare size.
* Step3: divide the k numbers into two parts, i and k-i, and we can use the function 
*        in the first step to find the maximum lengths of i and k-i in the two arrays. Then 
*        use the second step to fuse them. Finally we find the maximum from all the results.
*
* Time complexity O(nk^2), Space complexity O(k^2)
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result(k);
        for (int i = max(0, k - n); i <= k && i <= m; ++i) {
            vector<int> v1 = maxArray(nums1, i);
            vector<int> v2 = maxArray(nums2, k - i);
            vector<int> c = merge(v1, v2, k);
            if (greater(c, 0, result, 0)) result = c;
        }
        return result;
    }
    vector<int> maxArray(vector<int> &nums, int k) {
        vector<int> result(k);
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            while (nums.size() - i + j > k && j > 0 && result[j - 1] < nums[i]) --j;
            if (j < k) result[j++] = nums[i];
        }
        return result;
    } 
    
    bool greater(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    
    vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans(k);
        for (int r = 0, i = 0, j = 0; r < k; ++r) ans[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        return ans;
    }
};