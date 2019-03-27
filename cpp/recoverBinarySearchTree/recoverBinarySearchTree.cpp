// Source : https://leetcode.com/problems/recover-binary-search-tree
// Author : Nan
// Date   : 2019-03-27
// Runtime: 40 ms

/*
* MorrisTraversal.  
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
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root, *prev = NULL, *first = NULL, *second = NULL, *parent = NULL;
        bool flag = true;
        while (cur != NULL) {
            if (cur->left == NULL) {
                if (parent && parent->val > cur->val) {
                    if (!first) first = parent;
                    second = cur;
                }
                parent = cur;
                //printf("%d ", cur->val);
                cur = cur->right;
            }
            else {
                // find predecessor
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    prev->right = NULL;
                    //printf("%d ", cur->val);
                    if (parent && parent->val > cur->val) {
                        if (!first) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};