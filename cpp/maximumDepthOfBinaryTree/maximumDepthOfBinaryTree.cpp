// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : Nan
// Date   : 2019-03-29
// Runtime: 16 ms

/*
* Tree traversal.  
*
* Time complexity O(n), Space complexity O(logn)
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 1;
        getD(root, res, 1);
        return res;
        
    }
    void getD(TreeNode* p, int &res, int d) {
        res = max(res, d);
        if (p->left) getD(p->left, res, d + 1);
        if (p->right) getD(p->right, res, d + 1);
    }
};