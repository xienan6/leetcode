// Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author : Nan
// Date   : 2019-08-18
// Runtime: 20 ms

/*
* Inorder.
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
    int kthSmallest(TreeNode* root, int k) {
        int res, cnt = 0;
        dfs(root, k, res, cnt);
        return res;
    }
    void dfs(TreeNode *t, int &k, int &res, int &cnt) {
        if (!t || cnt >= k) return;
        dfs(t->left, k, res, cnt);
        ++cnt;
        if (cnt == k) res = t->val;
        dfs(t->right, k, res, cnt);
    }
};