// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Nan
// Date   : 2019-04-30
// Runtime: 4 ms

/*
* Use a stack in place of recursive solution.
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            res.push_back(t->val);
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
        return res;
    }
};
