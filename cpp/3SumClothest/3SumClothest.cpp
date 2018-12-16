// Source : https://leetcode.com/problems/3sum-closest/description/
// Author : Nan
// Date   : 2018-12-16
// 125 / 125 test cases passed.
// Runtime: 4 ms

/*
* You can sort the array firstly. Then traverse the array, 
* and use two pointer from start and end. Because of sorted already, 
* you can find all answer in O(n^2) time. Like 3Sum problem.
*
* Time complexity O(n^2), Space complexity O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int front, bottom, sum, n = nums.size();
        sort(nums.begin(), nums.end());
        long long result, dif = LONG_LONG_MAX, tar = target;
        for (int i = 0; i < n - 2; i++) {
            front = i + 1;
            bottom = n - 1;
            while (front < bottom) {
                sum = nums[i] + nums[front] + nums[bottom];
                if (tar > sum) front++;
                else if (tar < sum) bottom--;
                else return target;
                if (abs(tar - sum) < dif) {
                    result = sum;
                    dif = abs(tar - sum);
                }   
            }
        }
        return result;
    }
};