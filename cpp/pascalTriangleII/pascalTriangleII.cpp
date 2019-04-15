// Source : https://leetcode.com/problems/pascals-triangle-ii/
// Author : Nan
// Date   : 2019-04-15
// Runtime: 4 ms

/*
* Simulate.      
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for(int i = 1; i < rowIndex + 1; ++i)
            for(int j = i; j >= 1; --j)
                res[j] += res[j-1];
        return res;
    }
};