// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Nan
// Date   : 2019-04-01
// Runtime: 16 ms

/*
* Recursion. The first one in preorder is root. 
* Find index i in inorder. [0,i-1] is left tree 
* and [i+1, :] is right tree.  
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        return getSubTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, m);
    }
    TreeNode* getSubTree(vector<int>& preorder, vector<int>& inorder, int pLeft, int pRight, int iLeft, int iRight, unordered_map<int, int> &m) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = m[preorder[pLeft]];
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = getSubTree(preorder, inorder, pLeft + 1, pLeft + i - iLeft, iLeft, i - 1, m);
        cur->right = getSubTree(preorder, inorder, pLeft + i - iLeft + 1, pRight, i + 1, iRight, m);
        return cur;
    }
};