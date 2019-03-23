// Source : https://leetcode.com/problems/unique-binary-search-trees/
// Author : Nan
// Date   : 2019-03-23
// Runtime: 4 ms

/*
* DP. Each node i can be a root and its left 
* children are [1,i-1] and its right children are [i+1,n].          
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> c(n + 1, 0);
        c[0] = 1;
        for (int num = 1; num <= n; ++num) for (int i = 0; i <= num - 1; ++i) c[num] += c[i] * c[num - 1 - i];   
        return c[n];
    }
};