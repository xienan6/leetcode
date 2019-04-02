// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Nan
// Date   : 2019-04-02
// Runtime: 16 ms

/*
* Recursion. The last one in postorder is root. 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        return getSubTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
    }
    TreeNode* getSubTree(vector<int>& inorder, vector<int>& postorder, int iLeft, int iRight, int pLeft, int pRight, unordered_map<int, int> &m) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = m[postorder[pRight]];
        TreeNode *cur = new TreeNode(postorder[pRight]);
        cur->left = getSubTree(inorder, postorder, iLeft, i - 1, pLeft, pLeft + i - 1 - iLeft, m);
        cur->right = getSubTree(inorder, postorder, i + 1, iRight, pLeft + i - iLeft, pRight - 1, m);
        return cur;
    }
};