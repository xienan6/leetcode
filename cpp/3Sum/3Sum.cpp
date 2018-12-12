// Source : https://leetcode.com/problems/3sum
// Author : Nan
// Date   : 2018-12-09
// 313 / 313 test cases passed.
// Runtime: 72 ms

/*
* You can sort the array firstly. Then traverse the array, 
* and use two pointer from start and end. Because of sorted already, 
* you can find all answer in O(n^2) time.
* Notice that nSum questions only need O(n-1) Time complexity.
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());//nlgn
        int len = nums.size();
        vector<int> newr(3);
        int top, bottom;
        for (int i = 0; i < len-2; i++){//nn
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if (nums[i] > 0)
                break;
            newr[0] = nums[i];
            top = i + 1;
            bottom = len - 1;
            while (1) {
                if (nums[top] + nums[bottom] == -newr[0]) {
                    newr[1] = nums[top];
                    newr[2] = nums[bottom];
                    result.push_back(newr);
                    top++;
                    bottom--;
                    while (top < bottom && nums[top] == nums[top-1]) {
                        top++;
                    }
                    while (top < bottom && nums[bottom] == nums[bottom+1]) {
                        bottom--;
                    }
                    
                    
                }
                else if (nums[top] + nums[bottom] > -newr[0]) {
                    bottom--;
                }
                else if (nums[top] + nums[bottom] < -newr[0]) {
                    top++;
                }
                if (top >= bottom) {
                    break;
                }
            }
        }
        
        return result;
    }
};
