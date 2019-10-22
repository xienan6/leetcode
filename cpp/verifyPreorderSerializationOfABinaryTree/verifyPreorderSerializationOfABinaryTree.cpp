// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
// Author : Nan
// Date   : 2019-10-22
// Runtime: 4 ms

/*
* Calculate capacity and each number can add 2 capacity.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int capacity = 1;
        preorder += ",";
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] != ',') continue;
            if (--capacity < 0) return false;
            if (preorder[i - 1] != '#') capacity += 2;
        }
        return capacity == 0;
    }
    
};