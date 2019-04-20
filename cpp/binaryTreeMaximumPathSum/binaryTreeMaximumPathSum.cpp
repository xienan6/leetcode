// Source : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author : Nan
// Date   : 2019-04-20
// Runtime: 36 ms

/*
* Recursion. Find left max and right max and compare. 
*
* Time complexity O(n), Space complexity O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        fun(root, res);
        return res;
    }
    int fun(TreeNode* t, int &res) {
        if (!t) return 0;
        int left = max(fun(t->left, res), 0);
        int right = max(fun(t->right, res), 0);
        res = max(res, left + right + t->val);
        return max(left, right) + t->val;
    }
};