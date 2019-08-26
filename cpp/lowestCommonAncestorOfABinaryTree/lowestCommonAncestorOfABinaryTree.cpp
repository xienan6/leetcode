// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// Author : Nan
// Date   : 2019-08-26
// Runtime: 16 ms

/*
* Recursion solution.
*
* Time complexity O(logn), Space complexity O(1)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left && left != p && left != q) return left;
        TreeNode *right = lowestCommonAncestor(root->right, p , q);
        if (left && right) return root;
        return left ? left : right;
    }
};