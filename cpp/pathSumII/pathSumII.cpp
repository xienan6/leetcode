// Source : https://leetcode.com/problems/path-sum/
// Author : Nan
// Date   : 2019-04-09
// Runtime: 36 ms

/*
* Recursion.  
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> r;
        find(root, sum, res, r);
        return res;
    }
    void find(TreeNode *t, int sum, vector<vector<int>> &res, vector<int> r) {
        if (!t) return;
        r.push_back(t->val);
        if (sum - t->val == 0 && !t->left && !t->right) {
            res.push_back(r);
            return;
        }
        find(t->left, sum - t->val, res, r);
        find(t->right, sum - t->val, res, r);
    }
};