// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : Nan
// Date   : 2019-04-07
// Runtime: 16 ms

/*
* Recursion.  
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int l = minDepth(root->left), r = minDepth(root->right);
        return 1 + (min(l, r) ? min(l, r) : max(l, r));
    }
};