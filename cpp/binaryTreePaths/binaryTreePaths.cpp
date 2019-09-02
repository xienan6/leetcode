// Source : https://leetcode.com/problems/binary-tree-paths/
// Author : Nan
// Date   : 2019-09-02
// Runtime: 4 ms

/*
* Recursion solution.  
*
* Time complexity O(n), Space complexity O(nlogn)
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) find(to_string(root->val), root, res);
        return res;
    }
    void find(string s, TreeNode *root, vector<string> &res) {
        if (!root->left && !root->right) {
            res.push_back(s);
            return;
        }
        if (root->left) find(s + "->" + to_string(root->left->val), root->left, res);
        if (root->right) find(s + "->" + to_string(root->right->val), root->right, res);
    }
};