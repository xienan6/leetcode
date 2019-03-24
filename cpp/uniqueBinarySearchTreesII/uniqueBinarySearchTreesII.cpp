// Source : https://leetcode.com/problems/unique-binary-search-trees-ii
// Author : Nan
// Date   : 2019-03-24
// Runtime: 20 ms

/*
* Recursive solution. Each node i can be a root and its left 
* children are [1,i-1] and its right children are [i+1,n].          
*
* Time complexity O(2^n), Space complexity O(2^n)
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> r;
        if (n == 0) return r;
        return gerSubTrees(1, n + 1);
    }
    vector<TreeNode*> gerSubTrees(int l, int r) {
        vector<TreeNode*> subTree;
        if (l >= r) {
            subTree.push_back(NULL);
            return subTree;
        }
        if (l == r - 1) {
            subTree.push_back(new TreeNode(l));
            return subTree;
        }
        for (int i = l; i < r; ++i) {
            vector<TreeNode*> leftSubTree = gerSubTrees(l, i);
            vector<TreeNode*> rightSubTree = gerSubTrees(i + 1, r);
            for (int m = 0; m < leftSubTree.size(); ++m) {
                for (int n = 0; n < rightSubTree.size(); ++n) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[m];
                    root->right = rightSubTree[n];
                    subTree.push_back(root);
                }
             }
        }
        return subTree;
    }
};