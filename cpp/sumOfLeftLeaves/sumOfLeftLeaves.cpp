// Source : https://leetcode.com/problems/sum-of-left-leaves/
// Author : Nan
// Date   : 2019-12-28
// Runtime: 4 ms

/*
* DFS.
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
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* r) {
        if (!r) return;
        if (r->left && !r->left->left && !r->left->right) {
            res += r->left->val;
        }
        else {
            dfs(r->left);
        }
        dfs(r->right);
    }
private:
    int res = 0;
};