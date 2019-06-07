// Source : https://leetcode.com/problems/binary-tree-right-side-view/
// Author : Nan
// Date   : 2019-06-07
// Runtime: 0 ms

/*
* BFS.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front();
                if (i == n - 1) res.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                q.pop();
            }
        }
        return res;
    }
};