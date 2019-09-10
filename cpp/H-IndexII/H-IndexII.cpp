// Source : https://leetcode.com/problems/h-index-ii/
// Author : Nan
// Date   : 2019-09-10
// Runtime: 16 ms

/*
* Binary search.
*
* Time complexity O(logn), Space complexity O(1)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), left = 0, right = len - 1;
        while (left <= right) {
            int mid = 0.5 * (left + right);
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] > len - mid) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};