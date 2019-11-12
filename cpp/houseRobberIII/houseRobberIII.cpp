// Source : https://leetcode.com/problems/house-robber-iii/
// Author : Nan
// Date   : 2019-11-12
// Runtime: 44 ms

/*
* Recursive dp.
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
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode *root) {
        if (!root) return vector<int>(2, 0);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> res(2, 0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
        return res;
    }
};