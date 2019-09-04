// Source : https://leetcode.com/problems/single-number-iii/
// Author : Nan
// Date   : 2019-09-04
// Runtime: 0 ms

/*
* Divide into two groups by a 0 bit. Then find two results like Single Number.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff=0; 
        for(int num :nums) 
            diff^=num; 
        diff&=-diff;
        vector<int> ret={0,0};
        for(int num : nums)
        {
            if(0==(num&diff))
                ret[0]^=num;
            else
                ret[1]^=num;
        }
        return ret;
    }
};