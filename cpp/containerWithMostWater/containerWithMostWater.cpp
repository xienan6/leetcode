// Source : https://leetcode.com/problems/container-with-most-water/description/
// Author : Nan
// Date   : 2018-12-13
// 50 / 50 test cases passed.
// Runtime: 12 ms

/*
* Use two pointers from left and right. Then calculate the area and find the max.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, result = -1;
        while (i < j) {
            result = max(result, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }
        return result;
    }
};
