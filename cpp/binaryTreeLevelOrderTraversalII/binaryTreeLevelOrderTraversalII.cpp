// Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : Nan
// Date   : 2019-04-03
// Runtime: 8 ms

/*
* BFS and reverse. 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> r;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                r.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                q.pop();
            }
            res.push_back(r);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};