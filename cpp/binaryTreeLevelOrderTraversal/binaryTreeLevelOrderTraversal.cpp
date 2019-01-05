// Source : https://leetcode.com/problems/binary-tree-level-order-traversal
// Author : Nan
// Date   : 2019-01-05
// 34 / 34 test cases passed.
// Runtime: 4 ms

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()){
            vector<int> r;
            int l = q.size();
            for (int i = 0; i < l; i++) {
                TreeNode* child = q.front();
                r.push_back(child->val);
                if (child->left != NULL) {
                    q.push(child->left);
                }
                if (child->right != NULL) {
                    q.push(child->right);
                }
                q.pop();
            }
            result.push_back(r);
        }
        return result;
    }
};