// Source : https://leetcode.com/problems/symmetric-tree/
// Author : Nan
// Date   : 2019-03-28
// Runtime: 8 ms

/*
* BFS.  
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else if (root->left == NULL && root->right == NULL) return true;
        else if (root->left == NULL || root->right == NULL || root->left->val != root->right->val) return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode *l, *r;
        while (!q.empty()) {
            l = q.front();
            q.pop();
            r = q.front();
            q.pop();
            if (l->left != NULL && r->right != NULL && l->left->val == r->right->val) {
                q.push(l->left);
                q.push(r->right);
            }
            else if (l->left != r->right) return false;
            if (l->right != NULL && r->left != NULL && l->right->val == r->left->val) {
                q.push(l->right);
                q.push(r->left);
            }
            else if (l->right != r->left) return false;
        }
        return true;
    }
};