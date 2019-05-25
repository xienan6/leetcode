// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author : Nan
// Date   : 2019-05-25
// Runtime: 4 ms

/*
* Two pointers.  
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i1 = 0, i2 = numbers.size() - 1;
        while(i1 < i2) {
            if (numbers[i1] + numbers[i2] == target) return {i1 + 1, i2 + 1};
            else if (numbers[i1] + numbers[i2] < target) ++i1;
            else --i2;
        }
        return {-1, -1};
    }
};