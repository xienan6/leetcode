// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
// Author : Nan
// Date   : 2019-04-04
// Runtime: 32 ms

/*
* Construct BST. [LEFT, MID) is left tree and 
* (MID, RIGHT] is right tree.  
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getSubTree(nums, 0, nums.size() - 1);
    }
    TreeNode* getSubTree(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) >> 1;
        TreeNode *t = new TreeNode(nums[mid]);
        t->left = getSubTree(nums, left, mid - 1);
        t->right = getSubTree(nums, mid + 1, right);
        return t;
    }
};