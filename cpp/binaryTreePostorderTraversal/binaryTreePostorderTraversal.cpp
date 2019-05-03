// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author : Nan
// Date   : 2019-05-03
// Runtime: 4 ms

/*
* Use a stack in place of recursive solution. The 
* mirror of ROOT-RIGHT-LEFT is LEFT-RIGHT-ROOT, which 
* is postorder.
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            res.insert(res.begin(), t->val);
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;
    }
};
