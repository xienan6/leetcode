// Source : https://leetcode.com/problems/validate-binary-search-tree
// Author : Nan
// Date   : 2019-01-04
// 75 / 75 test cases passed.
// Runtime: 8 ms

/*
* Inorder traversal.
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
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        if (root) {
            dfs(root, result);
        }
        int l = result.size();
        if (l <= 1) {
            return true;
        }
        else {
            for (int i = 0; i < l - 1; i++) {
                if (result[i] >= result[i + 1]) {
                    return false;
                }
            }
            return true;
        }
    }
    void dfs(TreeNode* treeNode, vector<int> &result) {
        if (treeNode->left) {
            dfs(treeNode->left, result);
        }
        result.push_back(treeNode->val);
        if (treeNode->right) {
            dfs(treeNode->right, result);
        }
    }
};