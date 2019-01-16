// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers
// Author : Nan
// Date   : 2019-01-16
// 110 / 110 test cases passed.
// Runtime: 0 ms

/*
* Pre-order.    
*
* Time complexity O(n), Space complexity O(1)
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root != NULL) {
            accessTree(root, 0, sum);
        }
        return sum;
    }
    void accessTree(TreeNode* t, int sum, int & result) {
        sum = sum * 10 + t->val;
        if (t->left != NULL) {
            accessTree(t->left, sum, result);
        }
        if (t->right != NULL) {
            accessTree(t->right, sum, result);
        }
        if (t->left == NULL && t->right == NULL) {
            result += sum;
        }
    }
};