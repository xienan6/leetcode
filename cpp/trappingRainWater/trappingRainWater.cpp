// Source : https://leetcode.com/problems/trapping-rain-water/
// Author : Nan
// Date   : 2019-01-05
// 315 / 315 test cases passed.
// Runtime: 8 ms

/*
* Use two pointers to find the leftmax and the 
* right max, then calculate the difference.
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, left = 0, right = height.size() - 1;
        if (right <= 1) return 0;
        int leftmax = height[left], rightmax = height[right];
        while (left <= right) {
            if (leftmax < rightmax) {
                result += leftmax - height[left++];
                leftmax = max(leftmax, height[left]);
            } else {
                result += rightmax - height[right--];
                rightmax = max(rightmax, height[right]);
            }
        }
        return result;
    }
};