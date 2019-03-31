// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Nan
// Date   : 2019-03-31
// Runtime: 24 ms

/*
* Recursion. The first one in preorder is root. 
* Find index i in inorder. [0,i-1] is left tree 
* and [i+1, :] is right tree.  
*
* Time complexity O(n!), Space complexity O(n)
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 1;
        getD(root, res, 1);
        return res;
        
    }
    void getD(TreeNode* p, int &res, int d) {
        res = max(res, d);
        if (p->left) getD(p->left, res, d + 1);
        if (p->right) getD(p->right, res, d + 1);
    }
};